/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** *
*/

#include "CommandSGT.hpp"

using namespace network;

void CommandSGT::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandSGT::clone() const
{
    return std::make_unique<CommandSGT>();
}
