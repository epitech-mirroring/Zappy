/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ProtocolHandler
*/

#include "ProtocolHandler.hpp"

using namespace network;

ProtocolHandler::ProtocolHandler(CommandFactory& factory)
    : _factory(factory)
{
}

void ProtocolHandler::handleData(const std::vector<std::string>& data)
{
    for (const auto& line : data) {
        std::istringstream iss(line);
        std::string commandName;
        iss >> commandName;

        auto command = _factory.createCommand(commandName);
        if (command) {
            command->execute(iss);
        }
    }
}
