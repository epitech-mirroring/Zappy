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
    #include "network/command/factory/CommandFactory.hpp"

namespace network {
    class AProtocolHandler {
    public:
        /**
         * @brief Construct a new AProtocolHandler object
         */
        AProtocolHandler() noexcept;
        /**
         * @brief Destroy the AProtocolHandler object
         */
        ~AProtocolHandler() noexcept = default;

        /**
         * @brief Handle the connection to the server
         * @param socket (socket of the client)
         */
        virtual void handleCommunication(std::unique_ptr<ASocket>& socket,
            const std::string& commandName) noexcept final;
        protected:
            std::unique_ptr<CommandFactory> _commandFactory;
    };
} // namespace network //
#endif /* !APROTOCOLHANDLER_HPP_ */
