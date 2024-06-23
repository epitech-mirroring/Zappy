from .AbstractAction import AbstractAction
from ..Objects import AbstractObject


class Incantation(AbstractAction):

    def __init__(self):
        super().__init__(300)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Incantation\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == 'ko':
            return True
        if response == 'Elevation underway':
            return False
        if response.startswith('Current level: '):
            bot.level = int(response[15:])
            if bot.debug:
                print(f"Bot as leveled up to level {bot.level}")
            return True


