/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Trantorian
*/

#ifndef TRANTORIAN_
#define TRANTORIAN_

    #include <iostream>
    #include <vector>

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
             * @return vector of ints
             */
            std::vector<int, int> getPosition();

            /**
             * @brief Set trantorian team
             * @param teamName
             */
            void setTeam(std::string teamName);
            /**
             * @brief Get trantorian team
             * @return std::string
             */
            std::string getTeam();

            /**
             * @brief Set trantorian's lifetime
             * @param lifetime
             */
            void setLifetime(int lifetime);
            /**
             * @brief Get trantorian lifetime
             * @return int
             */
            int getLifetime();

            /**
             * @brief Set trantorian alive
             * @param bool
             */
            void setIsAlive(bool isAlive);
            /**
             * @brief Get trantorian alive
             * @return bool
             */
            bool getIsAlive();

            /**
             * @brief Set trantorian action
             * @param bool
             */
            void setAction(bool Action);
            /**
             * @brief Get trantorian action
             * @return bool
             */
            bool getAction();

            /**
             * @brief Set trantorian id
             * @param int
             */
            void setId(int id);
            /**
             * @brief Get trantorian id
             * @return int
             */
            int getId();

            /**
             * @brief Set trantorian level
             * @param int
             */
            void setLevel(int level);
            /**
             * @brief Get trantorian level
             * @return int
             */
            int getLevel();

        private:
            std::vector<int, int> _postion;
            std::string _team;
            int _lifetimeRemaining;
            bool _alive;
            bool _action;
            int _id;
            int _level;
    };
} // namespace GUI

#endif // TRANTORIAN_
