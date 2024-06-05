/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ASocket
*/

#ifndef ASOCKET_HPP_
    #define ASOCKET_HPP_

    #include <iostream>

namespace network {
    class ASocket {
    public:
        /**
         * @brief Construct a new ASocket object
         */
        ASocket() = default;
        /**
         * @brief Destroy the ASocket object
         */
        virtual ~ASocket() noexcept = default;

        /**
         * @brief Connect to the server
         * @param hostname (hostname of the server)
         * @param port (port of the server)
         */
        virtual void connect(const std::string &hostname,
            unsigned int port) = 0;
        /**
         * @brief Close the connection to the server
         */
        virtual void close() = 0;
        /**
         * @brief Send data to the server
         * @param data (data to send)
         */
        virtual void send(const std::string &data) = 0;
        /**
         * @brief Receive data from the server
         * @return std::string (data received)
         */
        [[nodiscard]] virtual std::string receive() = 0;
    };
} // namespace network //
#endif /* !ASOCKET_HPP_ */
