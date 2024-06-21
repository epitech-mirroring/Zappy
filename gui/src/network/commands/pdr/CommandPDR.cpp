/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPDR
*/

#include "CommandPDR.hpp"

using namespace network;

void CommandPDR::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandPDR::clone() const
{
    return std::make_unique<CommandPDR>();
}
