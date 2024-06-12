/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPpo
*/

#include "CommandPpo.hpp"

using namespace network;

void CommandPpo::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    socket->send(data);
}

std::unique_ptr<ICommand> CommandPpo::clone() const
{
    return std::make_unique<CommandPpo>(*this);
}

void CommandPpo::linkTeams(GUI::Teams *teams)
{
    _teams = teams;
}
