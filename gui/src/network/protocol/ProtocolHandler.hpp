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
         * @param world Reference to the World object
         */
        ProtocolHandler(GUI::World &world, GUI::Teams &teams) noexcept;

        /**
         * @brief Destroy the Protocol Handler object
         */
        ~ProtocolHandler() noexcept = default;

        /**
         * @brief Handle the command
         * @param socket Socket of the client
         * @param commandName Name of the command
         */
        void handleCommand(std::unique_ptr<ASocket>& socket, const std::string& commandName,
            const std::string& args) noexcept;

        /**
         * @brief Handle the response
         * @param socket Socket of the client
         * @param response Response from the server
         */
        void handleResponse(std::unique_ptr<ASocket>& socket, const std::string& response) noexcept;

    protected:
        std::unique_ptr<CommandFactory> _commandFactory;  ///< Command factory
    };
} // namespace network //
#endif /* !PROTOCOLHANDLER_HPP_ */
