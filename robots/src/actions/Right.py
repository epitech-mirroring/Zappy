from src import AbstractAction


class Right(AbstractAction):

    def __init__(self):
        super().__init__(7)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Right\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            bot.direction = (bot.direction.value + 1) % 4
        else:
            print(f"Right failed: {response}")
            exit(1)
