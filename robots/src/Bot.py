import threading
import time
import random
from enum import Enum

from .Network import NetworkManager
from .Objects import AbstractObject, Food, Linemate, Deraumere, Sibur, Mendiane, \
    Thystame, Phiras, Egg
from .World import World
from .actions import AbstractAction
from .actions.DropDown import DropDown
from .actions.Fork import Fork
from .actions.Forward import Forward
from .actions.Incantation import Incantation
from .actions.Look import Look
from .actions.PickUp import PickUp
from .actions.Right import Right
from .actions.Left import Left
from .actions.Inventory import Inventory as InventoryAction


incantation_requirements: dict[int, dict[str, int]] = {
    1: {
        "players": 1,
        "linemate": 1,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0
    },
    2: {
        "players": 2,
        "linemate": 1,
        "deraumere": 1,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0
    },
    3: {
        "players": 2,
        "linemate": 2,
        "deraumere": 0,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 2,
        "thystame": 0
    },
    4: {
        "players": 4,
        "linemate": 1,
        "deraumere": 1,
        "sibur": 2,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0
    },
    5: {
        "players": 4,
        "linemate": 1,
        "deraumere": 2,
        "sibur": 1,
        "mendiane": 3,
        "phiras": 0,
        "thystame": 0
    },
    6: {
        "players": 6,
        "linemate": 1,
        "deraumere": 2,
        "sibur": 3,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0
    },
    7: {
        "players": 6,
        "linemate": 2,
        "deraumere": 2,
        "sibur": 2,
        "mendiane": 2,
        "phiras": 2,
        "thystame": 1
    }
}

ticks_before_rescan = 20
ticks_before_inventory_rescan = 126

def parse_item(item: str) -> AbstractObject or None:
    if item == "player":
        return None
    if item == "food":
        return Food()
    if item == "linemate":
        return Linemate()
    if item == "deraumere":
        return Deraumere()
    if item == "sibur":
        return Sibur()
    if item == "mendiane":
        return Mendiane()
    if item == "phiras":
        return Phiras()
    if item == "thystame":
        return Thystame()
    if item == "egg":
        return Egg()
    return None


class Inventory:
    inventory: list[AbstractObject] = []

    def __init__(self):
        self.inventory = []

    def add_item(self, item: AbstractObject):
        # Find the item in the inventory
        for i in self.inventory:
            if isinstance(i, item.__class__):
                i.add(item)
                return
        # If the item is not in the inventory, add it
        self.inventory.append(item)

    def add_one_of(self, item: AbstractObject.__class__):
        # Find the item in the inventory
        for i in self.inventory:
            if isinstance(i, item):
                i.add_one()
                return
        # If the item is not in the inventory, add it
        self.inventory.append(item())

    def remove_item(self, item: AbstractObject) -> bool:
        # Find the item in the inventory
        for i in self.inventory:
            if isinstance(i, item.__class__):
                i.add(item)
                return True
        return False

    def get_item(self,
                 item: AbstractObject.__class__) -> AbstractObject or None:
        # Find the item in the inventory
        for i in self.inventory:
            if isinstance(i, item):
                return i
        return None

    def get_item_count(self, item: AbstractObject.__class__ or str) -> int:
        # Find the item in the inventory
        for i in self.inventory:
            # if item is a string, it's the name of the item
            if isinstance(item, str):
                if i.get_name() == item:
                    return i.count
            elif isinstance(i, item):
                return i.count
        return 0

    def clear(self):
        self.inventory = []


class Direction(Enum):
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3

    def right(self) -> 'Direction':
        return Direction((self.value + 1) % 4)

    def left(self) -> 'Direction':
        return Direction((self.value - 1) % 4)


def cells_to_direction(cell_from: tuple[int, int], cell_to: tuple[int, int]) \
        -> Direction:
    if cell_from[0] == cell_to[0]:
        if cell_from[1] > cell_to[1]:
            return Direction.NORTH
        else:
            return Direction.SOUTH
    else:
        if cell_from[0] > cell_to[0]:
            return Direction.WEST
        else:
            return Direction.EAST


class Bot:
    network_manager: NetworkManager
    team: str
    network_thread: threading.Thread
    actionQueue: list[AbstractAction] = []
    remaining_places_in_team: int
    world: World = None
    level: int = 1
    inventory: Inventory = Inventory()
    position: tuple[int, int] = (0, 0)
    direction: Direction = Direction.NORTH
    last_scan_time: float = 0
    last_inventory_scan_time: float = 0
    server_frequency: float or None = None
    debug: bool = False

    def __init__(self, network_manager: NetworkManager, team: str):
        self.network_manager = network_manager
        self.team = team
        self.remaining_places_in_team = 0

    def add_action(self, action: AbstractAction):
        self.actionQueue.append(action)

    def scan(self):
        self.last_scan_time = time.time()
        for i in range(4):
            self.add_action(Look())
            self.add_action(Right())

    def handle_response(self, response: str):
        response = response.strip()
        if len(response) == 0:
            return
        if self.world is None:
            if response == 'WELCOME':
                self.network_manager.send(f"%s\n" % self.team)
            else:
                # If response is two numbers, it's the world size
                if response.count(' ') == 1:
                    x, y = response.split(' ')
                    width = int(x)
                    height = int(y)
                    self.world = World(width, height)
                else:
                    self.remaining_places_in_team = int(response)
        else:
            if response == "dead":
                self.network_manager.close()
                if self.debug:
                    print("Dead")
                return
            action = self.actionQueue[0]
            duration = time.time() - action.requested_time
            expected_duration = action.time_to_execute  # In ticks
            if self.server_frequency is None:
                self.server_frequency = duration / expected_duration
            else:
                self.server_frequency = 0.9 * self.server_frequency + 0.1 * (
                    duration / expected_duration)
            should_remove_action = action.handle_response(response, self)
            if should_remove_action is None or should_remove_action:
                self.actionQueue.pop(0)

    def find_nearest(self, item: AbstractObject.__class__ or str) -> tuple[int, int] or None:
        min_distance = 1000000
        nearest_food: tuple[int, int] = (0, 0)
        found = False
        for x in range(-2*self.level, 2*self.level):
            for y in range(-2*self.level, 2*self.level):
                coords = (self.position[0] + x, self.position[1] + y)
                objects = self.world.get_objects(coords[0], coords[1])
                for obj in objects:
                    match = False
                    if isinstance(item, str):
                        match = obj.get_name() == item
                    else:
                        match = isinstance(obj, item)
                    if match:
                        distance = abs(self.position[0] - coords[0]) + abs(
                            self.position[1] - coords[1])
                        if distance < min_distance:
                            min_distance = distance
                            nearest_food = coords
                            found = True
        if not found:
            if self.debug:
                print("No %s found" % item)
            return None
        if self.debug:
            print(f"Nearest %s at {nearest_food}" % item)
        return nearest_food

    def rotate_to_face(self, direction: Direction,
                       current_direction: Direction = None) -> int:
        if current_direction is None:
            current_direction = self.direction
        if current_direction == direction:
            return 0
        if current_direction == Direction.NORTH:
            if direction == Direction.EAST:
                self.add_action(Right())
                return 1
            elif direction == Direction.SOUTH:
                self.add_action(Right())
                self.add_action(Right())
                return 2
            elif direction == Direction.WEST:
                self.add_action(Left())
                return 1
        elif current_direction == Direction.EAST:
            if direction == Direction.SOUTH:
                self.add_action(Right())
                return 1
            elif direction == Direction.WEST:
                self.add_action(Right())
                self.add_action(Right())
                return 2
            elif direction == Direction.NORTH:
                self.add_action(Left())
                return 1
        elif current_direction == Direction.SOUTH:
            if direction == Direction.WEST:
                self.add_action(Right())
                return 1
            elif direction == Direction.NORTH:
                self.add_action(Right())
                self.add_action(Right())
                return 2
            elif direction == Direction.EAST:
                self.add_action(Left())
                return 1
        elif current_direction == Direction.WEST:
            if direction == Direction.NORTH:
                self.add_action(Right())
                return 1
            elif direction == Direction.EAST:
                self.add_action(Right())
                self.add_action(Right())
                return 2
            elif direction == Direction.SOUTH:
                self.add_action(Left())
                return 1
        return 0

    def a_star_towards(self, target: tuple[int, int]):
        explored = []
        to_explore = [self.position]
        came_from = {}
        g_score = {self.position: 0}
        f_score = {self.position: abs(self.position[0] - target[0]) + abs(
            self.position[1] - target[1])}
        while len(to_explore) != 0:
            current = to_explore.pop(0)
            if current == target:
                path = [current]
                while current in came_from:
                    current = came_from[current]
                    path.append(current)
                path.reverse()
                action_pushed = 0
                current_direction = self.direction
                for i in range(1, len(path)):
                    direction = cells_to_direction(path[i - 1], path[i])
                    rotate_needed = (
                        self.rotate_to_face(direction, current_direction))
                    if rotate_needed > 0:
                        action_pushed += rotate_needed
                        current_direction = direction
                    else:
                        self.add_action(Forward())
                        action_pushed += 1
                    if action_pushed >= 10:
                        break
                return
            explored.append(current)
            for i in range(4):
                new_cell = current
                if i == 0:
                    new_cell = (new_cell[0], new_cell[1] - 1)
                elif i == 1:
                    new_cell = (new_cell[0] + 1, new_cell[1])
                elif i == 2:
                    new_cell = (new_cell[0], new_cell[1] + 1)
                elif i == 3:
                    new_cell = (new_cell[0] - 1, new_cell[1])
                if new_cell in explored:
                    continue
                if new_cell not in to_explore:
                    to_explore.append(new_cell)
                tentative_g_score = g_score[current] + 1
                if (new_cell in g_score and
                        tentative_g_score >= g_score[new_cell]):
                    continue
                came_from[new_cell] = current
                g_score[new_cell] = tentative_g_score
                f_score[new_cell] = (g_score[new_cell] +
                                     abs(new_cell[0] - target[0]) +
                                     abs(new_cell[1] - target[1]))
                to_explore.sort(key=lambda x: f_score[x])

    def wander(self):
        rand_x = random.randint(self.position[0] - self.world.width // 2,
                                self.position[0] + self.world.width // 2)
        rand_y = random.randint(self.position[1] - self.world.height // 2,
                                self.position[1] + self.world.height // 2)
        self.a_star_towards((rand_x, rand_y))

    def feed(self):
        nearest_food = self.find_nearest(Food)
        # If distance too far scan around
        if self.server_frequency is not None and self.debug:
            print(f"Server frequency: {self.server_frequency}")
        if (self.server_frequency is not None and
                (time.time() - self.last_scan_time) > ticks_before_rescan /
                self.server_frequency):
            if self.debug:
                print("Scanning")
            self.scan()
            return
        if nearest_food is None:
            if self.debug:
                print("Wandering")
            self.wander()
            return
        distance = abs(self.position[0] - nearest_food[0]) + abs(
            self.position[1] - nearest_food[1])
        if distance > 1:
            if self.debug:
                print("Moving towards food")
            self.a_star_towards(nearest_food)
        else:
            if self.debug:
                print("Picking up food")
                print("There was %d food at the position %d %d" % (self.world.get_objects_by_type_on_cell(nearest_food[0], nearest_food[1], Food).count, nearest_food[0], nearest_food[1]))

            self.add_action(PickUp(Food()))

    def level_up(self):
        requirements: dict[str, int] = incantation_requirements[self.level]
        has_all = True
        requirement_pos: dict[str, tuple[int, int]] = {}
        for i in requirements:
            if i == "players":
                continue
            if self.inventory.get_item_count(i) < requirements[i]:
                if self.debug:
                    print(f"Missing {i}")
                has_all = False
                nearest_item = self.find_nearest(i)
                if nearest_item is not None:
                    requirement_pos[i] = nearest_item
        if not has_all:
            nearest_requirement = None
            min_distance = 1000000
            for i in requirement_pos:
                distance = abs(self.position[0] - requirement_pos[i][0]) + abs(
                    self.position[1] - requirement_pos[i][1])
                if distance < min_distance:
                    min_distance = distance
                    nearest_requirement = i
            if nearest_requirement is not None:
                if min_distance > 1:
                    if self.debug:
                        print("Moving towards requirement")
                    self.a_star_towards(requirement_pos[nearest_requirement])
                else:
                    if self.debug:
                        print("Picking up requirement")
                    self.add_action(PickUp(parse_item(nearest_requirement)))
            else:
                if (self.server_frequency is not None and
                        (time.time() - self.last_scan_time) > ticks_before_rescan /
                        self.server_frequency):
                    if self.debug:
                        print("Scanning")
                    self.scan()
                    return
                if self.debug:
                    print("Wandering")
                self.wander()
        else:
            if self.debug:
                print("I have the requirements")
            if (self.server_frequency is not None and
                    (time.time() - self.last_inventory_scan_time) > ticks_before_inventory_rescan /
                    self.server_frequency):
                if self.debug:
                    print("Scanning inventory")
                self.add_action(InventoryAction())
                self.last_inventory_scan_time = time.time()
                return
            if requirements["players"] > 1:
                if self.debug:
                    print("Waiting for other players")
                return
            else:
                if self.debug:
                    print("Starting incantation")
                for i in requirements:
                    if i == "players":
                        continue
                    if requirements[i] > 0:
                        for j in range(requirements[i]):
                            self.add_action(DropDown(parse_item(i)))
                self.add_action(Incantation())

    def logic(self):
        food_urge = 10  # FIXME Update food urge computation
        level_urge = 0  # FIXME Update level urge computation
        for i in self.inventory.inventory:
            if isinstance(i, Food):
                food_urge -= i.count

        if food_urge > level_urge:
            if self.debug:
                print("Feeding")
            self.feed()
        else:
            if self.debug:
                print("Leveling up")
            self.level_up()

    def start(self):
        self.network_thread = threading.Thread(
            target=self.network_manager.start)
        self.network_thread.daemon = True
        self.network_manager.add_response_handler(self.handle_response)
        self.network_thread.start()

        time.sleep(1)

        if self.remaining_places_in_team > 0:
            self.remaining_places_in_team -= 1
            Fork().handle_response("ok", self)

        while True:
            if not self.network_manager.isRunning:
                break
            if self.world is None:
                continue
            if len(self.actionQueue) != 0:
                if not self.actionQueue[0].has_been_executed:
                    self.actionQueue[0].execute(self)
                else:
                    continue
            else:
                self.logic()

        self.network_thread.join()
        exit(0)

