import threading
import time
from enum import Enum

from .Network import NetworkManager
from .Objects import AbstractObject, Food
from .World import World
from .actions import AbstractAction
from .actions.Forward import Forward
from .actions.Look import Look
from .actions.PickUp import PickUp
from .actions.Right import Right
from .actions.Left import Left


class Inventory:
    inventory: list[AbstractObject] = []

    def __init__(self):
        self.inventory = []

    def add_item(self, item: AbstractObject):
        # Find the item in the inventory
        for i in self.inventory:
            if i.__class__ == item.__class__:
                i.add(item)
                return
        # If the item is not in the inventory, add it
        self.inventory.append(item)

    def remove_item(self, item: AbstractObject) -> bool:
        # Find the item in the inventory
        for i in self.inventory:
            if i.__class__ == item.__class__:
                i.add(item)
                return True
        return False

    def get_item(self,
                 item: AbstractObject.__class__) -> AbstractObject or None:
        # Find the item in the inventory
        for i in self.inventory:
            if i.__class__ == item:
                return i
        return None

    def get_item_count(self, item: AbstractObject.__class__) -> int:
        # Find the item in the inventory
        for i in self.inventory:
            if i.__class__ == item:
                return i.count
        return 0

    def clear(self):
        self.inventory = []


class Direction(Enum):
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3


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
    server_frequency: float or None = None

    def __init__(self, network_manager: NetworkManager, team: str):
        self.network_manager = network_manager
        self.team = team
        self.remaining_places_in_team = 0

    def add_action(self, action: AbstractAction):
        action.set_requested_time(time.time())
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
                exit(0)
            action = self.actionQueue.pop(0)
            duration = time.time() - action.requested_time
            expected_duration = action.time_to_execute  # In ticks
            if self.server_frequency is None:
                self.server_frequency = duration / expected_duration
            else:
                self.server_frequency = 0.9 * self.server_frequency + 0.1 * (
                    duration / expected_duration)
            action.handle_response(response, self)

    def find_nearest_food(self) -> tuple[int, int]:
        min_distance = 1000000
        nearest_food: tuple[int, int] = (0, 0)
        for x in range(2 * self.level):
            for y in range(2 * self.level):
                coords = (self.position[0] + x, self.position[1] + y)
                objects = self.world.get_objects(coords[0], coords[1])
                for obj in objects:
                    if obj.__class__ == Food.__class__:
                        distance = abs(self.position[0] - coords[0]) + abs(
                            self.position[1] - coords[1])
                        if distance < min_distance:
                            min_distance = distance
                            nearest_food = coords
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

    def feed(self):
        nearest_food = self.find_nearest_food()
        distance = abs(self.position[0] - nearest_food[0]) + abs(
            self.position[1] - nearest_food[1])
        # If distance too far scan around
        ticks_before_rescan = 20
        if (distance > self.world.height or distance > self.world.width) and (
                (time.time() - self.last_scan_time) > ticks_before_rescan /
                self.server_frequency):
            self.scan()
        elif distance > 1:
            self.a_star_towards(nearest_food)
        else:
            self.add_action(PickUp(Food()))

    def level_up(self):
        # FIXME Implement level up logic
        pass

    def logic(self):
        food_urge = 10  # FIXME Update food urge computation
        level_urge = 0  # FIXME Update level urge computation
        for i in self.inventory.inventory:
            if i.__class__ == Food.__class__:
                food_urge -= i.count

        if food_urge > level_urge:
            self.feed()
        else:
            self.level_up()

    def start(self):
        self.network_thread = threading.Thread(
            target=self.network_manager.start)
        self.network_thread.daemon = True
        self.network_manager.add_response_handler(self.handle_response)
        self.network_thread.start()

        while True:
            if self.world is None:
                continue
            if len(self.actionQueue) != 0:
                if not self.actionQueue[0].has_been_executed:
                    self.actionQueue.pop(0).execute(self)
                else:
                    continue
            else:
                self.logic()
