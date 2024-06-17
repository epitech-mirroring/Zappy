/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandBCT
*/

#include "CommandBCT.hpp"

using namespace network;

void CommandBCT::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandBCT::clone() const
{
    return std::make_unique<CommandBCT>();
}
