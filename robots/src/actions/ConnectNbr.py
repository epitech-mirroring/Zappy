from .AbstractAction import AbstractAction


class ConnectNbr(AbstractAction):

    def __init__(self):
        super().__init__(0)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Connect_nbr\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        bot.remaining_places_in_team = int(response)
