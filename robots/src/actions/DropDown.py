from src import AbstractAction, AbstractObject


class DropDown(AbstractAction):
    object: AbstractObject

    def __init__(self, to_drop: AbstractObject):
        super().__init__(7)
        self.object = to_drop

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Set " + self.object.get_name() + "\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            new_item = self.object.__class__()
            bot.inventory.remove_item(new_item)
            bot.world.add_object(bot.position[0], bot.position[1], new_item)
        else:
            print(f"Drop down failed: {response}")


