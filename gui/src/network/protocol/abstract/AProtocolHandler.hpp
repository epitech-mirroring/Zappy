/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AProtocolHandler
*/

#ifndef APROTOCOLHANDLER_HPP_
    #define APROTOCOLHANDLER_HPP_

    #include <memory>
    #include "network/protocol/interface/IProtocolHandler.hpp"

namespace network {
    class AProtocolHandler {
    public:
        /**
         * @brief Construct a new AProtocolHandler object
         */
        AProtocolHandler() noexcept = default;
        /**
         * @brief Destroy the AProtocolHandler object
         */
        ~AProtocolHandler() noexcept = default;

        /**
         * @brief Handle the connection to the server
         * @param socket (socket of the client)
         */
        virtual void handleCommunication(std::unique_ptr<ASocket>& socket) noexcept final;
    };
} // namespace network //
#endif /* !APROTOCOLHANDLER_HPP_ */
