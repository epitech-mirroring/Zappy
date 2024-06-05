/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Client
*/

#include "Client.hpp"

using namespace network;

Client::Client(const std::string& hostname, unsigned int port)
    :   _hostname(hostname)
    ,   _port(port)
    ,   _socket(std::make_unique<TCPSocket>())
    ,   _protocolHandler(std::make_unique<ProtocolHandler>())
{
}

void Client::handleConnection()
{
    _socket->connect(_hostname, _port);
}

void Client::handleDisconnection()
{
    _socket->close();
}

void Client::handleCommunication()
{
    _protocolHandler->handleCommunication(_socket);
}

