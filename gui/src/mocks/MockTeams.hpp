/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MockTeams
*/

#ifndef MOCKTEAMS_
    #define MOCKTEAMS_

    #include <iostream>
    #include <list>
    #include "MockTrantorians.hpp"

namespace GUI {
    class MockTrantorians; // Forward declaration

    class MockTeams {
        public:
            /**
             * @brief Create Team object
             */
            MockTeams(std::string name = "");
            /**
             * @brief Destroy Team object
             */
            ~MockTeams() = default;

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
             * @brief Add new MockTrantorians to team
             * @param MockTrantorians GUI::MockTrantorians object
             */
            void addMockTrantorians(GUI::MockTrantorians& MockTrantorians);

            /**
             * @brief Get list of MockTrantorians in the team
             * @return list of MockTrantorians objects
             */
            [[nodiscard]] std::list<GUI::MockTrantorians> getMockTrantoriansList() const;

            /**
             * @brief Add team to teams list
             * @param team GUI::MockTeams object
             */
            static void addMockTeamToMockTeamsList(const GUI::MockTeams& team);

            /**
             * @brief Get list of teams
             * @return list of teams objects
             */
            [[nodiscard]] static std::list<GUI::MockTeams>& getMockTeamsList();

            /**
             * @brief Get team by name
             * @param name std::string of team's name
             * @return MockTeams object
             */
            [[nodiscard]] static MockTeams* getTeamByName(const std::string& name);

            /**
             * @brief Get MockTrantorians by id
             * @param id int of MockTrantorians's id
             * @return MockTrantorians object
             */
            [[nodiscard]] MockTrantorians getMockTrantoriansById(std::string id);

        private:
            std::string _name;
            std::list<GUI::MockTrantorians> _MockTrantorians;

            // Static member to hold all teams
            static std::list<GUI::MockTeams> _Mockteams;
    };
} // namespace GUI

#endif // TEAMS_
