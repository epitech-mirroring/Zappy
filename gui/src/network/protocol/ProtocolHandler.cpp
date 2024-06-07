/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ProtocolHandler
*/

#include "ProtocolHandler.hpp"

using namespace network;

void ProtocolHandler::handleUtilsCommunication(ASocket &socket) noexcept
{
    (void)socket;
    /**
     * Function to handle OUR protocol if we want to send bonus data
     * Example:
    */
    std::string message = "Hello from the GUI";
    socket.send(message.c_str());

    std::string serverResponse = socket.receive();
    std::cout << "LOG: " << serverResponse << std::endl;
}
