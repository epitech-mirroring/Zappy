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
    #include <vector>
    #include "network/socket/ASocket.hpp"
    #include "exception/SocketException.hpp"

namespace network {
    class TCPSocket : public ASocket {
    public:
        /**
         * @brief Construct a new TCPSocket object and set it to -1
         */
        TCPSocket();

        /**
         * @brief Destroy the TCPSocket object, close the socket
         */
        ~TCPSocket();

        /**
         * @brief Connect to the server
         * @param hostname Hostname of the server
         * @param port Port of the server
         */
        void connect(const std::string &hostname, unsigned int port) final;

        /**
         * @brief Close the connection to the server
         */
        void close() final;

        /**
         * @brief Send data to the server
         * @param data Data to send
         */
        void send(const std::string &data) final;

        /**
         * @brief Receive data from the server
         * @return std::vector<std::string> Data received
         */
        [[nodiscard]] std::vector<std::string> receive() final;

        /**
         * @brief Get the socket file descriptor
         * @return int The socket file descriptor
         */
        [[nodiscard]] int getSockfd() const;

    protected:
        int _sockfd;    ///< Socket file descriptor
        struct sockaddr_in serv_addr;   ///< Server address
        std::string _partialBuffer; // Partial buffer
    };
} // namespace network //
#endif /* !TCPSOCKET_HPP_ */
