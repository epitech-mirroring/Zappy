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
        ProtocolHandler() noexcept;
        ~ProtocolHandler() noexcept = default;

        void handleCommand(std::unique_ptr<ASocket>& socket,
            const std::string& commandName) noexcept;
        void handleResponse(std::unique_ptr<ASocket>& socket,
            const std::string& response) noexcept;
    protected:
        std::unique_ptr<CommandFactory> _commandFactory;
    };
} // namespace network //
#endif /* !PROTOCOLHANDLER_HPP_ */
