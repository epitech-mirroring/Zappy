/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Trantorian
*/

#ifndef TRANTORIAN_
    #define TRANTORIAN_

    #include <iostream>
    #include <utility>
    #include "../position/Position.hpp"

namespace GUI {
    class Teams; // Forward declaration

    class Trantorian {
        public:
            /**
             * @brief Create trantorian object
             */
            Trantorian(int id = -1, int x = 0, int y = 0, int oritentation = 1,
                int level = 1, std::string teamName = "");
            /**
             * @brief Destroy trantorian object
             */
            ~Trantorian() = default;

            /**
             * @brief Set trantorian position
             * @param postion (int x, int y)
             */
            void setPosition(int x, int y);
            /**
             * @brief Get trantorian postion
             * @return pair of ints
             */
            [[nodiscard]] GUI::Position getPosition();

            /**
             * @brief Set trantorian team
             * @param team
             */
            void setTeam(Teams* team);
            /**
             * @brief Get trantorian team
             * @return Teams* pointer to team
             */
            [[nodiscard]] Teams* getTeam();

            /**
             * @brief Set trantorian's lifetime
             * @param lifetime
             */
            void setLifetime(int lifetime);
            /**
             * @brief Get trantorian lifetime
             * @return int representing life time remaining
             */
            [[nodiscard]] int getLifetime();

            /**
             * @brief Set trantorian alive
             * @param bool
             */
            void setIsAlive(bool isAlive);
            /**
             * @brief Get trantorian alive
             * @return false if dead, true if alive
             */
            [[nodiscard]] bool getIsAlive();

            /**
             * @brief Set trantorian action
             * @param bool
             */
            void setAction(bool Action);
            /**
             * @brief Get trantorian action
             * @return true if doing an action, false if not
             */
            [[nodiscard]] bool getAction();

            /**
             * @brief Set trantorian id
             * @param int
             */
            void setId(int id);
            /**
             * @brief Get trantorian id
             * @return int representing player's id
             */
            [[nodiscard]] int getId();

            /**
             * @brief Set trantorian level
             * @param level
             */
            void setLevel(int level);
            /**
             * @brief Get trantorian level
             * @return int representing player's level
             */
            [[nodiscard]] int getLevel();

            /**
             * @brief Compare two trantorians
             * @param other
             * @return true if equal, false if not
             */
            [[nodiscard]]
            bool operator==(const Trantorian& other) const;

            /**
             * @brief Set trantorian orientation
             * @param orientation
             */
            void setOrientation(int orientation);

        private:
            GUI::Position _position;
            Teams* _team;
            int _lifetimeRemaining;
            bool _alive;
            bool _action;
            int _id;
            int _level;
            int _orientation;
    };
} // namespace GUI

#endif // TRANTORIAN_
