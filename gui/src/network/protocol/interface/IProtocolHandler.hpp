/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IProtocolHandler
*/

#ifndef IPROTOCOLHANDLER_HPP_
    #define IPROTOCOLHANDLER_HPP_

    #include <memory>
    #include "network/socket/ASocket.hpp"

namespace network {
    class IProtocolHandler {
    public:
        /**
         * @brief Construct a new IProtocolHandler object
         */
        IProtocolHandler() noexcept = default;
        /**
         * @brief Destroy the IProtocolHandler object
         */
        virtual ~IProtocolHandler() noexcept = default;

        /**
         * @brief Handle the communication with the server
         * @param socket (socket of the client)
         */
        virtual void handleCommunication(std::unique_ptr<ASocket>& socket) = 0;
    };
} // namespace network //
#endif /* !IPROTOCOLHANDLER_HPP_ */
