/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSST
*/

#include "CommandSST.hpp"

using namespace network;

void CommandSST::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandSST::clone() const
{
    return std::make_unique<CommandSST>();
}
