/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Teams
*/

#ifndef TEAMS_
    #define TEAMS_

    #include <iostream>
    #include <list>
    #include "Trantorian.hpp"

namespace GUI
{
    class Teams
    {
        public:
            /**
             * @brief Create Team object
             */
            Teams(std::string name = "");
            /**
             * @brief Create Team object
             */
            ~Teams() = default;

            /**
             * @brief Set name of the team
             * @param name std::string of team's name
             */
            void setName(std::string name);
            /**
             * @brief Get team's name
             * @return std::string of team's name
             */
            [[nodiscard]] std::string getName();

            /**
             * @brief Add new trantorian to team
             * @param Trantorian object
             */
            void addTrantorian(GUI::Trantorian trantorian);
            /**
             * @brief Get list of trantorian in the team
             * @return list of trantorian objects
             */
            [[nodiscard]] std::list<GUI::Trantorian> getTrantorianList();

        private:
            std::string _name;
            std::list<GUI::Trantorian> _trantorians;
    };
} // namespace GUI

#endif // TEAMS_
