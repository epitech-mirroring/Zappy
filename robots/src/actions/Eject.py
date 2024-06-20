from src import AbstractAction


class Eject(AbstractAction):

    def __init__(self):
        super().__init__(7)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Eject\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            pass
        else:
            print(f"Eject failed: {response}")

