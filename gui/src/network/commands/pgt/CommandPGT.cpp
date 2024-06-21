/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPGT
*/

#include "CommandPGT.hpp"

using namespace network;

void CommandPGT::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPGT::clone() const
{
    return std::make_unique<CommandPGT>();
}
