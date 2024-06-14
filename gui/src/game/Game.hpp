/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

    #include <sstream>
    #include <raylib.h>
    #include "world/World.hpp"
    #include "trantorians/Teams.hpp"
    #include "network/Client.hpp"
    #include "network/commands/factory/CommandFactory.hpp"
    #include "network/protocol_handler/ProtocolHandler.hpp"

namespace GUI {
class Game {
    public:
        Game(std::string hostname, unsigned int port);
        ~Game();

        void initGame(); // init the game elements (world, tiles, teams, etc)
        void runGame(); //main loop call the client read here

        void createWorld(std::vector<std::string> data); //create the _world object by receveing the MSZ command
        void initTimeUnit(std::vector<std::string> data); //create the time unit by receiving the TNA command

    private:
        World _world;
        Teams _teams;
        network::Client _client;
        unsigned int _timeUnit;
};
} // namespace GUI //
#endif /* !GAME_HPP_ */

