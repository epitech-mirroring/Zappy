/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTNA
*/

#include "CommandTNA.hpp"

using namespace network;

void CommandTNA::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandTNA::clone() const
{
    return std::make_unique<CommandTNA>();
}
