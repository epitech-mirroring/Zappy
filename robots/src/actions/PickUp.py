from src import AbstractAction, AbstractObject


class PickUp(AbstractAction):
    object: AbstractObject

    def __init__(self, to_pick_up: AbstractObject):
        super().__init__(7)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Take object\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            new_item = self.object.__class__()
            bot.world.remove_object(bot.position[0], bot.position[1], new_item)
            bot.inventory.add_item(new_item)
        else:
            print(f"Pick up failed: {response}")


