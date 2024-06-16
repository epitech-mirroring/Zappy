/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPPO
*/

#include "CommandPPO.hpp"

using namespace network;

void CommandPPO::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPPO::clone() const
{
    return std::make_unique<CommandPPO>();
}

