/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <memory>
    #include <iostream>
    #include "network/socket/TCPSocket.hpp"
    #include "network/protocol/ProtocolHandler.hpp"

namespace network {
    class Client {
    public:
        Client(const std::string &hostname, unsigned int port);
        ~Client() = default;

        void handleConnection();
        void handleDisconnection();

        void handleCommunication();
    protected:
        unsigned int _port;
        std::string _hostname;
        std::unique_ptr<ASocket> _socket;
        std::unique_ptr<ProtocolHandler> _protocolHandler;
    };
} // namespace network //
#endif /* !CLIENT_HPP_ */
