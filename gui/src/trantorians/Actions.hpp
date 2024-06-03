/*
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
            [[nodiscard]] bool moveForward();
            /**
             * @brief Trantorian turn 90° right
             * @return true if action succeed
             */
            [[nodiscard]] bool turnRight();
            /**
             * @brief Trantorian turn 90° left
             * @return true if action succeed
             */
            [[nodiscard]] bool turnLeft();

            /**
             * @brief Trantorian look tiles around him
             * @return vector containing tiles positions
             */
            [[nodiscard]] std::vector<std::vector<int>> lookAround();
            /**
             * @brief Trantorian open inventory
             * @return map containing objects in inventory
             */
            [[nodiscard]] std::map<std::string, int> openInventory();
            /**
             * @brief Trantorian turn 90° left
             * @param text
             * @return true if action succeed
             */
            [[nodiscard]] bool broadcastText(std::string text);
            /**
             * @brief Number of team unused slots
             * @return int
             */
            [[nodiscard]] int connectNbr();
            /**
             * @brief Trantorian fork a player
             * @return true if action succeed
             */
            [[nodiscard]] bool forkPlayer();
            /**
             * @brief Death of a player
             */
            [[nodiscard]] void playerDead();

            /**
             * @brief Trantorian take an object
             * @return true if action succeed
             */
            [[nodiscard]] bool takeObj();
            /**
             * @brief Trantorian set an object
             * @return true if action succeed
             */
            [[nodiscard]] bool setObj();
            /**
             * @brief Trantorian start incantation
             * @return true if action succeed
             */
            [[nodiscard]] bool startIncantation();
    };
} // namespace GUI

#endif // ACTIONS_HPP_
