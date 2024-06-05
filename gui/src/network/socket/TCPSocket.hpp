/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TCPSocket
*/

#ifndef TCPSOCKET_HPP_
    #define TCPSOCKET_HPP_

    #include <cstring>
    #include <iostream>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include "network/socket/ASocket.hpp"
    #include "exception/SocketException.hpp"

namespace network {
    class TCPSocket : public ASocket {
    public:
        TCPSocket();
        ~TCPSocket();

        void connect(const std::string &hostname, unsigned int port) final;
        void close() final;
        void send(const std::string &data) final;
        [[nodiscard]] std::string receive() final;
    protected:
        int _sockfd;
        struct sockaddr_in serv_addr;
    };
} // namespace network //
#endif /* !TCPSOCKET_HPP_ */
