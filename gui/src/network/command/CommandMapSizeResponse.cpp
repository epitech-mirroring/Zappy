/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** CommandMapSizeResponse
*/

#include "CommandMapSizeResponse.hpp"

using namespace network;

void CommandMapSizeResponse::execute(std::unique_ptr<ASocket> &socket,
    const std::string &data)
{
    (void)socket;
    std::istringstream responseStream(data);
    std::string commandName;
    int x, y;
    responseStream >> commandName >> x >> y;
    std::cout << "Map size: " << x << " " << y << std::endl;
}

std::unique_ptr<ICommand> CommandMapSizeResponse::clone() const
{
    return std::make_unique<CommandMapSizeResponse>(*this);
}
