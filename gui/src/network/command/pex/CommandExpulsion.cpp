/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSize
*/

#include "CommandExpulsion.hpp"

using namespace network;

CommandExpulsion::CommandExpulsion()
    :   _world(nullptr)
{
}

void CommandExpulsion::execute(std::unique_ptr<ASocket> &socket,
    const std::string &data)
{
    (void)socket;
    std::istringstream responseStream(data);
    std::string commandName;
    int playerNumber;
    responseStream >> commandName >> playerNumber;
}

std::unique_ptr<ICommand> CommandExpulsion::clone() const
{
    return std::make_unique<CommandExpulsion>(*this);
}

void CommandExpulsion::linkWorld(GUI::World *world)
{
    _world = world;
}
