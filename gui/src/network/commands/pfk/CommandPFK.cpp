/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPFK
*/

#include "CommandPFK.hpp"

using namespace network;

void CommandPFK::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPFK::clone() const
{
    return std::make_unique<CommandPFK>();
}
