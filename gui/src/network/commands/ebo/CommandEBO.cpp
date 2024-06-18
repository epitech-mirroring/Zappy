/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandEBO
*/

#include "CommandEBO.hpp"

using namespace network;

void CommandEBO::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandEBO::clone() const
{
    return std::make_unique<CommandEBO>();
}
