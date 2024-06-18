/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandENW
*/

#include "CommandENW.hpp"

using namespace network;

void CommandENW::execute(std::istringstream &iss)
{
    if (_callback)
        _callback(iss);
}

std::unique_ptr<ICommand> CommandENW::clone() const
{
    return std::make_unique<CommandENW>();
}
