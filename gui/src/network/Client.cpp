/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Client
*/

#include "Client.hpp"

using namespace network;

Client::Client(const std::string &hostname, unsigned int port)
    : _hostname(hostname)
    , _socket(std::make_unique<TCPSocket>())
    , _port(port)
{
}

void Client::handleConnection()
{
    _socket->connect(_hostname, _port);

    auto welcomeMessages = _socket->receive();

    for (const auto& welcomeMessage : welcomeMessages) {
        if (welcomeMessage.find("WELCOME") == std::string::npos) {
            throw std::runtime_error("Connection failed");  //change to an IException ClientError
        }
    }
}


std::vector<std::string> Client::readData()
{
    fd_set readfds;
    int sockfd = _socket->getSockfd();

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int activity = select(sockfd + 1, &readfds, nullptr, nullptr, nullptr);

    if (activity < 0 && errno != EINTR) {
        std::cerr << "Select error" << std::endl;
        return {};
    }

    if (FD_ISSET(sockfd, &readfds)) {
        return _socket->receive();
    }

    return {};
}

void Client::handleDisconnection()
{
    _socket->close();
}
