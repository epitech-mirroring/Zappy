/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSEG
*/

#include "CommandSEG.hpp"

using namespace network;

void CommandSEG::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandSEG::clone() const
{
    return std::make_unique<CommandSEG>();
}
