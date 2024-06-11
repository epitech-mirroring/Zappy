/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSizeResponse
*/

#include "CommandMapSizeResponse.hpp"

using namespace network;

CommandMapSizeResponse::CommandMapSizeResponse()
    :   _world(nullptr)
{
}

void CommandMapSizeResponse::execute(std::unique_ptr<ASocket> &socket,
    const std::string &data)
{
    (void)socket;
    std::istringstream responseStream(data);
    std::string commandName;
    int x, y;
    responseStream >> commandName >> x >> y;
    std::cout << "Map size: " << x << " " << y << std::endl;
    if (_world) {
        _world->setWorldSize(x, y);
        std::cout << "World size set" << std::endl;
        std::cout << "World size: " << _world->getHeight() << " " << _world->getWidth() << std::endl;
    } else {
        std::cerr << "World pointer is null" << std::endl;
    }
}

std::unique_ptr<ICommand> CommandMapSizeResponse::clone() const
{
    return std::make_unique<CommandMapSizeResponse>(*this);
}

void CommandMapSizeResponse::linkWorld(GUI::World *world)
{
    _world = world;
}
