/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ProtocolHandler
*/

#ifndef PROTOCOLHANDLER_HPP_
    #define PROTOCOLHANDLER_HPP_

    #include <vector>
    #include <string>
    #include <sstream>
    #include "network/commands/factory/CommandFactory.hpp"

namespace network {
    class ProtocolHandler {
    public:
        ProtocolHandler(CommandFactory& factory);
        ~ProtocolHandler() = default;

        void handleData(const std::vector<std::string> &data);
    private:
        CommandFactory& _factory;
    };
} // namespace network //
#endif /* !PROTOCOLHANDLER_HPP_ */
