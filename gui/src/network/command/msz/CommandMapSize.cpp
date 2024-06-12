/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSize
*/

#include "CommandMapSize.hpp"

using namespace network;

void CommandMapSize::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    std::string command = "msz\n";
    socket->send(command);
}

std::unique_ptr<ICommand> CommandMapSize::clone() const
{
    return std::make_unique<CommandMapSize>(*this);
}

void CommandMapSize::linkWorld(GUI::World *world)
{
    _world = world;
}
