/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPBC
*/

#include "CommandPBC.hpp"

using namespace network;

void CommandPBC::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPBC::clone() const
{
    return std::make_unique<CommandPBC>();
}
