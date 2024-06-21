/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPEX
*/

#include "CommandPEX.hpp"

using namespace network;

void CommandPEX::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPEX::clone() const
{
    return std::make_unique<CommandPEX>();
}
