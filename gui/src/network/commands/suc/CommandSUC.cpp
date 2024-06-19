/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSUC
*/

#include "CommandSUC.hpp"

using namespace network;

void CommandSUC::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandSUC::clone() const
{
    return std::make_unique<CommandSUC>();
}
