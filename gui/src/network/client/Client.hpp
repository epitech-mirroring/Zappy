/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <iostream>
    #include "network/socket/TCPSocket.hpp"
    #include "network/protocol/IProtocolHandler.hpp"

namespace network {
    class Client {
    public:
        Client(const std::string &hostname, unsigned int port);
        ~Client() = default;

        void handleConnection();
        void handleDisconnection();

        void handleCommunicaiton();
    protected:
        unsigned int _port;
        std::string _hostname;
    };
} // namespace network //
#endif /* !CLIENT_HPP_ */
