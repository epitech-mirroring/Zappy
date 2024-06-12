/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ProtocolHandler
*/

#include "ProtocolHandler.hpp"

using namespace network;

ProtocolHandler::ProtocolHandler(GUI::World &world,
    GUI::Teams &teams) noexcept
    : _commandFactory(std::make_unique<CommandFactory>(world, teams))
{
}

void ProtocolHandler::handleCommand(std::unique_ptr<ASocket>& socket,
    const std::string& commandName, const std::string& args) noexcept
{
    auto command = _commandFactory->getCommand(commandName);
    std::string data = commandName + " " + args + "\n";
    if (command) {
        command->execute(socket, data);
    } else {
        std::cerr << "Unknown command: " << commandName << std::endl;
    }
}

void ProtocolHandler::handleResponse(std::unique_ptr<ASocket>& socket,
    const std::string& response) noexcept
{
    std::istringstream responseStream(response);
    std::string responseName;
    responseStream >> responseName;

    auto command = _commandFactory->getResponseCommand(responseName);
    if (command) {
        command->execute(socket, response);
    } else
        std::cerr << "Unknown response: " << response << std::endl;
}
