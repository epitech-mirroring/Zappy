/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIN
*/

#include "CommandPIN.hpp"

using namespace network;

void CommandPIN::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPIN::clone() const
{
    return std::make_unique<CommandPIN>();
}
