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
    #include "trantorians/Trantorian.hpp"
    #include "network/Client.hpp"
    #include "network/commands/factory/CommandFactory.hpp"
    #include "network/protocol_handler/ProtocolHandler.hpp"
    #include "display/Display.hpp"

namespace GUI {
    class Game {
    public:
        /**
         * @brief Construct a new Game object
         * @param hostname Hostname of the server
         * @param port Port of the server
         */
        Game(std::string hostname, unsigned int port);
        /**
         * @brief Destroy the Game object
         */
        ~Game() = default;

        /**
         * @brief Initialize the game elements (Window, Client, World)
         */
        void initGame();
        /**
         * @brief Run the game loop
         */
        void runGame();

        /**
         * @brief Create the world object
         */
        void createWorld(std::vector<std::string> data);
        /**
         * @brief initialize the time unit of the game (ticks)
         */
        void initTimeUnit(std::vector<std::string> data);

        /**
         * @brief Initialize the callbacks of the game
         */
        void initializeCallbacks();

    private:
        World _world;                            // World object
        Teams _teams;                            // Teams object
        network::Client _client;                 // Client object
        network::CommandFactory _commandFactory; // CommandFactory object
        unsigned int _timeUnit;                  // Time unit of the game
        Display _display;                        // Display object
    };
} // namespace GUI //
#endif /* !GAME_HPP_ */

