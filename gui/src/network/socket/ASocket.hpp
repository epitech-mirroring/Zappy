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
        ASocket() = default;
        virtual ~ASocket() noexcept = default;

        virtual void connect(const std::string &hostname,
            unsigned int port) = 0;
        virtual void close() = 0;
        virtual void send(const std::string &data) = 0;
        [[nodiscard]] virtual std::string receive() = 0;
    };
} // namespace network //
#endif /* !ASOCKET_HPP_ */
