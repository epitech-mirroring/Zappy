/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandEDI
*/

#include "CommandEDI.hpp"

using namespace network;

void CommandEDI::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandEDI::clone() const
{
    return std::make_unique<CommandEDI>();
}
