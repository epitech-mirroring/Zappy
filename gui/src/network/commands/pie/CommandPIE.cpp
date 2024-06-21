/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIE
*/

#include "CommandPIE.hpp"

using namespace network;

void CommandPIE::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPIE::clone() const
{
    return std::make_unique<CommandPIE>();
}
