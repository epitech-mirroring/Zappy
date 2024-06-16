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
        /**
         * @brief Construct a new Protocol Handler object
         * @param CommandFactory &factory
         */
        ProtocolHandler(CommandFactory& factory);
        /**
         * @brief Destroy the Protocol Handler object
         */
        ~ProtocolHandler() = default;

        /**
         * @brief Handle the data
         * @param std::vector<std::string> &data
         */
        void handleData(const std::vector<std::string> &data);
    private:
        CommandFactory& _factory;   // Command factory
    };
} // namespace network //
#endif /* !PROTOCOLHANDLER_HPP_ */
