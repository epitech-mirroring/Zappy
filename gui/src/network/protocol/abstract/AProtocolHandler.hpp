/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AProtocolHandler
*/

#ifndef APROTOCOLHANDLER_HPP_
    #define APROTOCOLHANDLER_HPP_

    #include "network/protocol/interface/IProtocolHandler.hpp"

namespace network {
    class AProtocolHandler {
    public:
        AProtocolHandler() noexcept = default;
        ~AProtocolHandler() noexcept = default;

        virtual void handleCommunication(ASocket &socket) noexcept final;
    };
} // namespace network //
#endif /* !APROTOCOLHANDLER_HPP_ */
