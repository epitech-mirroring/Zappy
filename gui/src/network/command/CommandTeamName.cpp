/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTeamName
*/

#include "CommandTeamName.hpp"

using namespace network;

void CommandTeamName::execute(ASocket &socket)
{
    std::string request = "GRAPHIC\n";
    socket.send(request);
}
