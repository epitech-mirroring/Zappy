/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Client
*/

#include "Client.hpp"

using namespace network;

Client::Client(const std::string& hostname, unsigned int port, GUI::World& world)
    : _hostname(hostname), _port(port),
      _socket(std::make_unique<TCPSocket>()),
      _protocolHandler(std::make_unique<ProtocolHandler>(world))
{
}

void Client::handleConnection()
{
    _socket->connect(_hostname, _port);

    auto welcomeMessages = _socket->receive();
    for (const auto& welcomeMessage : welcomeMessages) {
        if (welcomeMessage.find("WELCOME") == std::string::npos) {
            throw std::runtime_error(                               //change to an IException
                "Failed to receive welcome message from server");
        }
    }
    _socket->send("GRAPHIC\n");
    processServerMessages();
}

void Client::handleDisconnection()
{
    _socket->close();
}

void Client::sendCommand(const std::string &commandName)
{
    _protocolHandler->handleCommand(_socket, commandName);
}

void Client::processServerMessages()
{
    fd_set readfds;
    int sockfd = _socket->getSockfd();

    while (true) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        int activity = select(sockfd + 1, &readfds, nullptr, nullptr, nullptr);

        if (activity < 0 && errno != EINTR) {
            std::cerr << "Select error" << std::endl;
            break;
        }

        if (FD_ISSET(sockfd, &readfds)) {
            auto responses = _socket->receive();
            for (const auto& response : responses)
                _protocolHandler->handleResponse(_socket, response);
        }
    }
}
