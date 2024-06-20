from . import AbstractAction


class Forward(AbstractAction):

    def __init__(self):
        super().__init__(7)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Forward\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            if bot.direction == bot.direction.NORTH:
                bot.position = (bot.position[0], bot.position[1] - 1)
            elif bot.direction == bot.direction.EAST:
                bot.position = (bot.position[0] + 1, bot.position[1])
            elif bot.direction == bot.direction.SOUTH:
                bot.position = (bot.position[0], bot.position[1] + 1)
            elif bot.direction == bot.direction.WEST:
                bot.position = (bot.position[0] - 1, bot.position[1])
        else:
            print(f"Forward failed: {response}")
            exit(1)
