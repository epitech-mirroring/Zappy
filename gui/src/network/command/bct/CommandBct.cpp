/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandBct
*/

#include "CommandBct.hpp"

using namespace network;

void CommandBct::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    std::string request = "bct " + data + "\n";
    socket->send(request);
}

std::unique_ptr<ICommand> CommandBct::clone() const
{
    return std::make_unique<CommandBct>(*this);
}

void CommandBct::linkWorld(GUI::World *world)
{
    _world = world;
}
