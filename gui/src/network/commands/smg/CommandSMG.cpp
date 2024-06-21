/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSMG
*/

#include "CommandSMG.hpp"

using namespace network;

void CommandSMG::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandSMG::clone() const
{
    return std::make_unique<CommandSMG>();
}
