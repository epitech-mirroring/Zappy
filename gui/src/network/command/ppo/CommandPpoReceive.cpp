/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPpoReceive
*/

#include "CommandPpoReceive.hpp"

using namespace network;

CommandPpoReceive::CommandPpoReceive()
    :   _teams(nullptr)
{
}

void CommandPpoReceive::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    (void)socket;
    std::istringstream responseStream(data);
    std::string commandName;
    int playerId, x, y, orientation;
    responseStream >> commandName >> playerId >> x >> y >> orientation;
    if(_teams) {
        for (auto &team : _teams->getTeamsList()) {
            for (auto &player : team.getTrantorianList()) {
                if (player.getId() == playerId) {
                    player.setPosition(x, y);
                    // player.setOrientation(static_cast<GUI::Orientation>(orientation));
                    return;
                }
            }
    }
}

std::unique_ptr<ICommand> CommandPpoReceive::clone() const
{
    return std::make_unique<CommandPpoReceive>(*this);
}

void CommandPpoReceive::linkTeams(GUI::Teams *teams)
{
    _teams = teams;
}
