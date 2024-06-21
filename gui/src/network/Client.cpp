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
            throw network::ClientException("CLIENT ERROR: Connection failed");
        }
    }
}

std::vector<std::string> Client::readData()
{
    fd_set readfds;
    int sockfd = _socket->getSockfd();
    struct timeval timeout;

    timeout.tv_sec = 0.1;
    timeout.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int activity = select(sockfd + 1, &readfds, nullptr, nullptr, &timeout);
    if (activity < 0) {
        if (errno != EINTR) {
            std::cerr << "Select error: " << strerror(errno) << std::endl;
        }
        return {};
    } else if (activity == 0) {
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
