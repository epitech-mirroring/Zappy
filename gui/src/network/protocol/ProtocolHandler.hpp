/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ProtocolHandler
*/

#ifndef PROTOCOLHANDLER_HPP_
    #define PROTOCOLHANDLER_HPP_

    #include <iostream>
    #include <sstream>
    #include <memory>
    #include "network/command/factory/CommandFactory.hpp"

namespace network {
    class ProtocolHandler {
    public:
        /**
         * @brief Construct a new Protocol Handler object
         */
        ProtocolHandler(GUI::World &world) noexcept;
        /**
         * @brief Destroy the Protocol Handler object
         */
        ~ProtocolHandler() noexcept = default;

        /**
         * @brief Handle the command
         * @param socket (socket of the client)
         * @param commandName (name of the command)
         */
        void handleCommand(std::unique_ptr<ASocket>& socket,
            const std::string& commandName) noexcept;
        /**
         * @brief Handle the response
         * @param socket (socket of the client)
         * @param response (response of the server)
         */
        void handleResponse(std::unique_ptr<ASocket>& socket,
            const std::string& response) noexcept;

    protected:
        std::unique_ptr<CommandFactory> _commandFactory;            // Command factory
    };
} // namespace network //
#endif /* !PROTOCOLHANDLER_HPP_ */
