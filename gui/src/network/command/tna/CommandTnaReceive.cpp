/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTnaReceive
*/

#include "CommandTnaReceive.hpp"

using namespace network;

CommandTnaReceive::CommandTnaReceive()
    :   _teams(nullptr)
{
}

void CommandTnaReceive::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    (void)socket;
    std::istringstream responseStream(data);
    std::string commandName;
    std::string teamName;
    responseStream >> commandName >> teamName;

    if (_teams) {
        GUI::Teams team(teamName);
        _teams->addTeamToTeamsList(team);

        std::cout << "Teams list:" << std::endl;
        for (const auto& team : _teams->getTeamsList()) {
            std::cout << "Team name: " << team.getName() << std::endl;
        }
    }
}

std::unique_ptr<ICommand> CommandTnaReceive::clone() const
{
    return std::make_unique<CommandTnaReceive>(*this);
}

void CommandTnaReceive::linkTeams(GUI::Teams *teams)
{
    _teams = teams;
}
