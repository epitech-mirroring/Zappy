/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AProtocolHandler
*/

#include "AProtocolHandler.hpp"

using namespace network;

void AProtocolHandler::handleCommunication(std::unique_ptr<ASocket>& socket) noexcept
{
    (void)socket;
    /**
     * Make the GUI protocol here
     * Example:
    */
    std::string message = "Hello from the GUI";
    socket->send(message.c_str());

    std::string serverResponse = socket->receive();
    std::cout << "LOG: " << serverResponse << std::endl;
}
