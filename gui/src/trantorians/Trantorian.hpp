/*
** File description:
** Trantorian
*/

#ifndef TRANTORIAN_
#define TRANTORIAN_

    #include <iostream>
    #include <utility>
    #include "../position/Position.hpp"

namespace GUI {
    class Trantorian {
        public:
            /**
             * @brief Create trantorian object
             */
            Trantorian();
            /**
             * @brief Destroy trantorian object
             */
            ~Trantorian();

            /**
             * @brief Set trantorian position
             * @param postion (int x, int y)
             */
            void setPosition(int x, int y);
            /**
             * @brief Get trantorian postion
             * @return pair of ints
             */
            GUI::Position getPosition();

            /**
             * @brief Set trantorian team
             * @param teamName
             */
            void setTeam(std::string teamName);
            /**
             * @brief Get trantorian team
             * @return std::string w/ team's name
             */
            std::string getTeam();

            /**
             * @brief Set trantorian's lifetime
             * @param lifetime
             */
            void setLifetime(int lifetime);
            /**
             * @brief Get trantorian lifetime
             * @return int representing life time remaining
             */
            int getLifetime();

            /**
             * @brief Set trantorian alive
             * @param bool
             */
            void setIsAlive(bool isAlive);
            /**
             * @brief Get trantorian alive
             * @return false if dead, true if alive
             */
            bool getIsAlive();

            /**
             * @brief Set trantorian action
             * @param bool
             */
            void setAction(bool Action);
            /**
             * @brief Get trantorian action
             * @return true if doing an action, false if not
             */
            bool getAction();

            /**
             * @brief Set trantorian id
             * @param int
             */
            void setId(int id);
            /**
             * @brief Get trantorian id
             * @return int representing player's id
             */
            int getId();

            /**
             * @brief Set trantorian level
             * @param level
             */
            void setLevel(int level);
            /**
             * @brief Get trantorian level
             * @return int representing player's level
             */
            int getLevel();

        private:
            GUI::Position _position;
            std::string _team;
            int _lifetimeRemaining;
            bool _alive;
            bool _action;
            int _id;
            int _level;
    };
} // namespace GUI

#endif // TRANTORIAN_
