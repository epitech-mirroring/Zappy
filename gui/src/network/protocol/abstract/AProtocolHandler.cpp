/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AProtocolHandler
*/

#include "AProtocolHandler.hpp"

using namespace network;

AProtocolHandler::AProtocolHandler() noexcept
    : _commandFactory(std::make_unique<CommandFactory>())
{
}

void AProtocolHandler::handleCommunication(std::unique_ptr<ASocket>& socket,
            const std::string& commandName) noexcept
{
    auto command = _commandFactory->getCommand(commandName);
    if (command) {
        command->execute(*socket);
        std::string response = socket->receive();
        std::cout << "Server response: " << response;
    } else {
        std::cerr << "Unknown command: " << commandName << std::endl;
    }
}
