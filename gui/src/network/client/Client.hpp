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
         * @param hostname Hostname of the server
         * @param port Port of the server
         * @param world Reference to the World object
         */
        Client(const std::string &hostname, unsigned int port,
            GUI::World &world, GUI::Teams &teams);

        /**
         * @brief Destroy the Client object
         */
        ~Client() = default;

        /**
         * @brief Handle the connection to the server
         */
        void handleConnection();

        /**
         * @brief Handle the disconnection from the server
         */
        void handleDisconnection();

        /**
         * @brief Send a command to the server
         * @param commandName Name of the command
         */
        void sendCommand(const std::string &commandName, const std::string &args);

        /**
         * @brief Process the server messages and handle them with the protocol handler
         */
        void processServerMessages();

    protected:
        unsigned int _port;     ///< Port of the server
        std::string _hostname;  ///< Hostname of the server
        std::unique_ptr<ASocket> _socket;   ///< Socket of the client
        std::unique_ptr<ProtocolHandler> _protocolHandler;  ///< Protocol handler of the client
    };
} // namespace network //
#endif /* !CLIENT_HPP_ */

