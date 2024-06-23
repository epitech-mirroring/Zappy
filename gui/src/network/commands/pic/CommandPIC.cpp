/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIC
*/

#include "CommandPIC.hpp"

using namespace network;

void CommandPIC::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPIC::clone() const
{
    return std::make_unique<CommandPIC>();
}
