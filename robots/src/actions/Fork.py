from .AbstractAction import AbstractAction

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
                # Execute './zappy_ai -p port -n name -h machine'
                os.execlp("./zappy_ai", "./zappy_ai", "-p",
                          str(bot.network_manager.serverPort), "-n", bot.team,
                          "-h", bot.network_manager.serverIP)
            elif pid > 0:
                pass
        else:
            if bot.debug:
                print(f"Fork failed: {response}")
            exit(1)
