/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MockTeams
*/

#include "MockTeams.hpp"

using namespace GUI;

std::list<GUI::MockTeams> MockTeams::_Mockteams;

MockTeams::MockTeams(std::string name)
    : _name(std::move(name))
{
}

void MockTeams::setName(std::string name)
{
    _name = std::move(name);
}

std::string MockTeams::getName() const
{
    return _name;
}

void MockTeams::addMockTrantorians(MockTrantorians& MockTrantorians)
{
    MockTrantorians.setTeam(this);
    _MockTrantorians.emplace_back(MockTrantorians);
}

std::list<MockTrantorians> MockTeams::getMockTrantoriansList() const
{
    return _MockTrantorians;
}

void MockTeams::addMockTeamToMockTeamsList(const MockTeams& team)
{
    for (const auto& existingTeam : _Mockteams) {
        if (existingTeam.getName() == team.getName()) {
            return;
        }
    }
    _Mockteams.emplace_back(team);
}

std::list<MockTeams>& MockTeams::getMockTeamsList()
{
    return _Mockteams;
}

MockTeams* MockTeams::getTeamByName(const std::string& name)
{
    for (auto &team : _Mockteams) {
        if (team.getName() == name)
            return &team;
    }
    return nullptr;
}

MockTrantorians MockTeams::getMockTrantoriansById(std::string id)
{
    for (auto &MockTrantorians : _MockTrantorians) {
        if (MockTrantorians.getId() == id)
            return MockTrantorians;
    }
    return MockTrantorians();
}
