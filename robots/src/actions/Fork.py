from .AbstractAction import AbstractAction
from ..Bot import Bot
from ..Network import NetworkManager

import os


class Fork(AbstractAction):
    # Lay an egg

    def __init__(self):
        super().__init__(42)

    def execute(self, bot):
        super().execute(bot)
        bot.network_manager.send("Fork\n")

    def handle_response(self, response: str, bot):
        super().handle_response(response, bot)
        if response == "ok":
            # Egg laid so we can fork
            pid = os.fork()
            if pid == 0:
                network = NetworkManager(bot.network_manager.serverPort,
                                         bot.network_manager.serverIP)
                bot = Bot(network, bot.team)
                bot.start()
            elif pid > 0:
                pass
        else:
            print(f"Fork failed: {response}")
            exit(1)
