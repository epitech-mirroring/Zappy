from .AbstractAction import AbstractAction
from ..Objects import AbstractObject, Food, Linemate, Deraumere, \
    Sibur, Mendiane, Phiras, Thystame, Egg


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


class Look(AbstractAction):

    def __init__(self):
        super().__init__(7)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Look\n")

    def handle_response(self, response: str, bot):
        # Items are given in the format: ["item1 item2 item3", "item4 item5
        # item6", ...] Where the cell order is from left to write, going from
        # us in the direction we are facing Each level adds a new line
        super().handle_response(response, bot)
        stripped = response.strip()[1:-1]
        cells = stripped.split(",")
        line_width = 1
        cell_on_line = 0
        for (i, items) in enumerate(cells):
            cells[i] = items.strip().split(" ")
            for item in cells[i]:
                x = 0
                y = 0
                if bot.direction == bot.direction.NORTH:
                    x = bot.position[0] - line_width // 2 + cell_on_line
                    y = bot.position[1] - i
                elif bot.direction == bot.direction.EAST:
                    x = bot.position[0] + i
                    y = bot.position[1] - line_width // 2 + cell_on_line
                elif bot.direction == bot.direction.SOUTH:
                    x = bot.position[0] + line_width // 2 - cell_on_line
                    y = bot.position[1] + i
                elif bot.direction == bot.direction.WEST:
                    x = bot.position[0] - i
                    y = bot.position[1] + line_width // 2 - cell_on_line
                parsed_item = parse_item(item)
                if parsed_item is not None:
                    bot.world.add_object(x, y, parsed_item)
            cell_on_line += 1
            if cell_on_line == line_width:
                line_width += 2
                cell_on_line = 0
