/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Actions
*/

#ifndef ACTIONS_HPP_
#define ACTIONS_HPP_

    #include <stdbool.h>
    #include <vector>
    #include <iostream>
    #include <map>

namespace GUI {
    enum action {
        Forward,
        Right,
        Left,
        Look,
        Inventory,
        Broadcast,
        Connect,
        Fork,
        Eject,
        Take,
        Set,
        Incantation
    };

    class Actions {
        public:
            /**
             * @brief 
             */
            Actions();
            ~Actions();

            /**
             * @brief Trantorian move up one tile
             * @return true if action succeed
             */
            bool moveForward();
            /**
             * @brief Trantorian turn 90° right
             * @return true if action succeed
             */
            bool turnRight();
            /**
             * @brief Trantorian turn 90° left
             * @return true if action succeed
             */
            bool turnLeft();

            /**
             * @brief Trantorian look tiles around him
             * @return vector containing tiles positions
             */
            std::vector<std::vector<int>> lookAround();
            /**
             * @brief Trantorian open inventory
             * @return map containing objects in inventory
             */
            std::map<std::string, int> openInventory();
            /**
             * @brief Trantorian turn 90° left
             * @param text
             * @return true if action succeed
             */
            bool broadcastText(std::string text);
            /**
             * @brief Number of team unused slots
             * @return int
             */
            int connectNbr();
            /**
             * @brief Trantorian fork a player
             * @return true if action succeed
             */
            bool forkPlayer();
            /**
             * @brief Death of a player
             */
            void playerDead();

            /**
             * @brief Trantorian take an object
             * @return true if action succeed
             */
            bool takeObj();
            /**
             * @brief Trantorian set an object
             * @return true if action succeed
             */
            bool setObj();
            /**
             * @brief Trantorian start incantation
             * @return true if action succeed
             */
            bool startIncantation();
    };
} // namespace GUI

#endif // ACTIONS_HPP_
