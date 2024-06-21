/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIC
*/

#include "CommandPIC.hpp"

using namespace network;

void CommandPIC::execute(std::istringstream &iss)
{
    (void)iss;
    return;
}

std::unique_ptr<ICommand> CommandPIC::clone() const
{
    return nullptr;
}
