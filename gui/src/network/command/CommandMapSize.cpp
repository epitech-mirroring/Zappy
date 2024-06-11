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
    std::string request = "msz\n";
    socket->send(request);
}

std::unique_ptr<ICommand> CommandMapSize::clone() const
{
    return std::make_unique<CommandMapSize>(*this);
}
