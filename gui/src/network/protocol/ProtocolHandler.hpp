/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ProtocolHandler
*/

#ifndef PROTOCOLHANDLER_HPP_
    #define PROTOCOLHANDLER_HPP_

    #include "network/protocol/abstract/AProtocolHandler.hpp"

namespace network {
    class ProtocolHandler : public AProtocolHandler {
    public:
        void handleUtilsCommunication(ASocket &socket) noexcept;
    };
} // namespace network //
#endif /* !PROTOCOLHANDLER_HPP_ */
