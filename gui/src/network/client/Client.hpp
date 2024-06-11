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
        /**
         * @brief Construct a new Client object
         * @param hostname (hostname of the server)
         * @param port (port of the server)
        */
        Client(const std::string &hostname, unsigned int port);
        /**
         * @brief Destroy the Client object
        */
        ~Client() = default;

        /**
         * @brief Handle the connection to the server
        */
        void handleConnection();
        /**
         * @brief Handle the disconnection to the server
        */
        void handleDisconnection();
        /**
         * @brief Handle the communication with the server
        */
        void sendCommand(const std::string &commandName);

        /**
         * @brief Process the server messages and handle them with the protocol
         */
        void processServerMessages();
    protected:
        unsigned int _port;     // Port of the server
        std::string _hostname;  // Hostname of the server
        std::unique_ptr<ASocket> _socket;   // Socket of the client
        std::unique_ptr<ProtocolHandler> _protocolHandler;  // Protocol handler of the client
    };
} // namespace network //
#endif /* !CLIENT_HPP_ */
