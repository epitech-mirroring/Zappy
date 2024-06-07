/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSize
*/

#include "CommandMapSize.hpp"

using namespace network;

void CommandMapSize::execute(ASocket &socket)
{
    std::string request = "msz\n";
    socket.send(request);
}
