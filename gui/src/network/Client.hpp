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

namespace network {
    class Client {
    public:
        /**
         * @brief Construct a new Client object
         * @param hostname Hostname of the server
         * @param port Port of the server
         */
        Client(const std::string &hostname, unsigned int port);
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
         * @brief Send data to the server
         * @param data Data to send
         */
        std::vector<std::string> readData();

        std::unique_ptr<ASocket> _socket;   ///< Socket of the client
    protected:
        unsigned int _port;     ///< Port of the server
        std::string _hostname;  ///< Hostname of the server
    };
} // namespace network //
#endif /* !CLIENT_HPP_ */
