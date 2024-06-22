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
    #include "objects/eggs/Egg.hpp"

namespace GUI {
    class Teams {
        public:
            /**
             * @brief Create Team object
             */
            Teams(std::string name = "");
            /**
             * @brief Destroy Team object
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
            [[nodiscard]] std::string getName() const;

            /**
             * @brief Add new trantorian to team
             * @param trantorian GUI::Trantorian object
             */
            void addTrantorian(Trantorian& trantorian);

            /**
             * @brief Get list of trantorian in the team
             * @return list of trantorian objects
             */
            [[nodiscard]] std::list<Trantorian>& getTrantorianList();

            /**
             * @brief Add team to teams list
             * @param team GUI::Teams object
             */
            static void addTeamToTeamsList(const GUI::Teams& team);

            /**
             * @brief Get list of teams
             * @return list of teams objects
             */
            [[nodiscard]] static std::list<GUI::Teams>& getTeamsList();

            /**
             * @brief Get team by name
             * @param name std::string of team's name
             * @return Teams object
             */
            [[nodiscard]] static Teams* getTeamByName(const std::string& name);

            /**
             * @brief Get trantorian by id
             * @param id int of trantorian's id
             * @return Trantorian object
             */
            [[nodiscard]] Trantorian getTrantorianById(std::string id);

            bool hasTrantorian(const std::string& id) const;

            /**
             * @brief Add a new egg to egg's list
             * @param Egg egg object
             * @return void (nothing to return)
             */
            void addEggToList(Egg newEgg);

            /**
             * @brief Remove egg from egg's list
             * @param string egg Id
             * @return void (nothing to return)
             */
            void removeEggFromList(std::string eggId);

            /**
             * @brief Get list of egg in the team
             * @return list of egg objects
             */
            [[nodiscard]] std::list<Egg> getEggList() const;

        private:
            std::string _name;
            std::list<Trantorian> _trantorians;
            std::list<Egg> _eggs;
            static std::list<GUI::Teams> _teams;
    };
} // namespace GUI

#endif // TEAMS_
