from src import AbstractAction


class Left(AbstractAction):

    def __init__(self):
        super().__init__(7)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Left\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            bot.direction = (bot.direction.value - 1) % 4
        else:
            print(f"Left failed: {response}")
            exit(1)
