/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMSZ
*/

#include "CommandMSZ.hpp"

using namespace network;

void CommandMSZ::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandMSZ::clone() const
{
    return std::make_unique<CommandMSZ>();
}
