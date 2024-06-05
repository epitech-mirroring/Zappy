/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IProtocolHandler
*/

#ifndef IPROTOCOLHANDLER_HPP_
    #define IPROTOCOLHANDLER_HPP_

    #include "network/socket/ASocket.hpp"

namespace network {
    class IProtocolHandler {
    public:
        IProtocolHandler() noexcept = default;
        virtual ~IProtocolHandler() noexcept = default;

        virtual void handleCommunication(ASocket socket) = 0;
    };
} // namespace network //
#endif /* !IPROTOCOLHANDLER_HPP_ */
