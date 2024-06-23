from .AbstractAction import AbstractAction


class Broadcast(AbstractAction):
    message: str

    def __init__(self, message: str):
        super().__init__(7)
        self.message = message

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Broadcast " + self.message + "\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            pass
        else:
            if bot.debug:
                print(f"Broadcast failed: {response}")
            exit(1)


