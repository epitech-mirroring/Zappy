from .AbstractAction import AbstractAction
from ..Objects import AbstractObject


class PickUp(AbstractAction):
    object: AbstractObject

    def __init__(self, to_pick_up: AbstractObject):
        super().__init__(7)
        self.object = to_pick_up

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Take " + self.object.get_name() + "\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            bot.world.remove_object_by_type(bot.position[0], bot.position[1], self.object.__class__)
            bot.inventory.add_one_of(self.object.__class__)
        else:
            if bot.debug:
                print(f"Pick up failed: {response}")
            bot.world.remove_all_of_type_on_cell(bot.position[0], bot.position[1], self.object.__class__)


