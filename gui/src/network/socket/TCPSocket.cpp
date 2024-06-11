/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TCPSocket
*/

#include "TCPSocket.hpp"

using namespace network;

TCPSocket::TCPSocket()
    : _sockfd(-1)
{
}

TCPSocket::~TCPSocket()
{
    if (_sockfd != -1)
        ::close(_sockfd);
}

void TCPSocket::connect(const std::string &hostname, unsigned int port)
{
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (_sockfd < 0)
        throw zappy::SocketException("SOCKET ERROR: opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname.c_str(), &serv_addr.sin_addr) <= 0)
        throw zappy::SocketException("SOCKET ERROR: Invalid address");
    if (::connect(_sockfd,
        (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        throw zappy::SocketException("SOCKET ERROR: Connection failed");
}

void TCPSocket::close()
{
    if (_sockfd != -1) {
        ::close(_sockfd);
        _sockfd = -1;
    }
}

void TCPSocket::send(const std::string &data)
{
    ::send(_sockfd, data.c_str(), data.size(), 0);
}

std::string TCPSocket::receive() {
    std::string data;
    char buffer[4096];
    int bytesRead = 0;

    while (true) {
        bytesRead = ::recv(_sockfd, buffer, sizeof(buffer), 0);
        if (bytesRead < 0) {
            throw zappy::SocketException("SOCKET ERROR: Reading failed");
        } else if (bytesRead == 0) {
            break;
        }
        data.append(buffer, bytesRead);
        if (data.find('\n') != std::string::npos) {
            break;
        }
    }
    return data;
}
