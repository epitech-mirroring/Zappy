/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPNW
*/

#include "CommandPNW.hpp"

using namespace network;

void CommandPNW::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPNW::clone() const
{
    return std::make_unique<CommandPNW>();
}
