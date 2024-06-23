from src.Bot import Bot
from src.Network import NetworkManager

import sys

if __name__ == '__main__':
    port: int or None = None
    host: str = "127.0.0.1"
    team: str or None = None
    debug: bool = False
    for (i, arg) in enumerate(sys.argv):
        if arg == "--help":
            print("USAGE: ./zappy_ai -p port -n name -h machine")
            sys.exit(0)
        if arg == "-p":
            if i + 1 < len(sys.argv):
                port = int(sys.argv[i + 1])
            else:
                print("USAGE: ./zappy_ai -p port -n name -h machine")
                print("Port is required")
                sys.exit(84)
        if arg == "-h":
            if i + 1 < len(sys.argv):
                host = sys.argv[i + 1]
            else:
                print("USAGE: ./zappy_ai -p port -n name -h machine")
                print("Host is required (default: '127.0.0.1')")
                sys.exit(84)
        if arg == "-n":
            if i + 1 < len(sys.argv):
                team = sys.argv[i + 1]
            else:
                print("USAGE: ./zappy_ai -p port -n name -h machine")
                print("Team name is required")
                sys.exit(84)
        if arg == "-v":
            debug = True
    if port is None:
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("You must specify a port")
        sys.exit(84)
    if team is None:
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("You must specify a team name")
        sys.exit(84)
    network = NetworkManager(port, host)
    bot = Bot(network, team)
    if debug:
        bot.debug = True
        print(f"Bot {team} started on {host}:{port}")
    bot.start()
    if debug:
        print("Bot stopped")
