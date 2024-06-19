/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSBP
*/

#include "CommandSBP.hpp"

using namespace network;

void CommandSBP::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandSBP::clone() const
{
    return std::make_unique<CommandSBP>();
}
