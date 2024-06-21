/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ASocket
*/

#ifndef ASOCKET_HPP_
    #define ASOCKET_HPP_

    #include <iostream>
    #include <vector>

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
         * @param hostname Hostname of the server
         * @param port Port of the server
         */
        virtual void connect(const std::string &hostname,
            unsigned int port) = 0;

        /**
         * @brief Close the connection to the server
         */
        virtual void close() = 0;

        /**
         * @brief Send data to the server
         * @param data Data to send
         */
        virtual void send(const std::string &data) = 0;

        /**
         * @brief Receive data from the server
         * @return std::vector<std::string> Data received
         */
        [[nodiscard]] virtual std::vector<std::string> receive() = 0;

        /**
         * @brief Get the socket file descriptor
         * @return int The socket file descriptor
         */
        [[nodiscard]] virtual int getSockfd() const = 0;
    };
} // namespace network
#endif /* !ASOCKET_HPP_ */
