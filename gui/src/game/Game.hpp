/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

    #include <raylib.h>
    #include "world/World.hpp"
    #include "trantorians/Teams.hpp"
    #include "network/Client.hpp"
    #include <sstream>

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
        std::shared_ptr<World> _world;
        std::shared_ptr<Teams> _teams;
        network::Client _client;
        unsigned int _timeUnit;
};
} // namespace GUI //
#endif /* !GAME_HPP_ */

