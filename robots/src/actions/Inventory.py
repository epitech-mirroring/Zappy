from .AbstractAction import AbstractAction
from .Look import parse_item
from ..Objects import AbstractObject


class Inventory(AbstractAction):

    def __init__(self):
        super().__init__(1)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Inventory\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        stripped = response.strip()[1:-1]
        slots = stripped.split(",")
        bot.inventory.clear()
        for items in slots:
            name, quantity = items.strip().split(" ")
            parsed: AbstractObject or None = parse_item(name)
            if parsed is not None:
                parsed.set_count(int(quantity))
                bot.inventory.add_item(parsed)


