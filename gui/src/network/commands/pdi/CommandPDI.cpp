/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPDI
*/

#include "CommandPDI.hpp"

using namespace network;

void CommandPDI::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPDI::clone() const
{
    return std::make_unique<CommandPDI>();
}
