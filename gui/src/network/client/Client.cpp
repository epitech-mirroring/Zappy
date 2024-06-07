/*
** EPITECH PROJECT, 2024
** Zappy
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

    std::string welcomeMessage = _socket->receive();
    if (welcomeMessage.find("WELCOME") == std::string::npos) {
        throw std::runtime_error("Failed to receive welcome message from server");
    }
    std::cout << "Server response: " << welcomeMessage << std::endl;

    _socket->send("GRAPHIC\n");

    std::string clientNumMessage = _socket->receive();
    std::string worldSizeMessage = _socket->receive();
    std::cout << "Server response: " << clientNumMessage << std::endl;
    std::cout << "Server response: " << worldSizeMessage << std::endl;
}

void Client::handleDisconnection()
{
    _socket->close();
}

void Client::sendCommand(const std::string &commandName)
{
    _protocolHandler->handleCommunication(_socket, commandName);
}

