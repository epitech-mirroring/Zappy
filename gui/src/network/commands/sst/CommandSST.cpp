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
    (void)iss;
    return;
}

std::unique_ptr<ICommand> CommandSST::clone() const
{
    return nullptr;
}
