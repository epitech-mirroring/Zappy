/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPLV
*/

#include "CommandPLV.hpp"

using namespace network;

void CommandPLV::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPLV::clone() const
{
    return std::make_unique<CommandPLV>();
}
