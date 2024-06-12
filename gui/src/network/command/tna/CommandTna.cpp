/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTna
*/

#include "CommandTna.hpp"

using namespace network;

void CommandTna::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    std::string request = "tna\n";
    socket->send(request);
}

std::unique_ptr<ICommand> CommandTna::clone() const
{
    return std::make_unique<CommandTna>(*this);
}

void CommandTna::linkTeams(GUI::Teams *teams)
{
    _teams = teams;
}
