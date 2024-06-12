/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandDthOfPlyr
*/

#include "CommandDthOfPlyr.hpp"

using namespace network;

CommandDthOfPlyr::CommandDthOfPlyr()
    :   _world(nullptr)
    ,   _trantorian(nullptr)
{
}

void CommandDthOfPlyr::execute(std::unique_ptr<ASocket> &socket,
    const std::string &data)
{
    (void)socket;
    std::istringstream responseStream(data);
    std::string commandName;
    int playerNumber;
    responseStream >> commandName >> playerNumber;
    std::cout << "Death of player number " << playerNumber << std::endl;
    if (_trantorian) {
        _trantorian->setIsAlive(false);
        std::cout << "Player " << playerNumber << " died." << std::endl;
    } else {
        std::cerr << "Trantorian pointer is null" << std::endl;
    }
}

std::unique_ptr<ICommand> CommandDthOfPlyr::clone() const
{
    return std::make_unique<CommandDthOfPlyr>(*this);
}

void CommandDthOfPlyr::linkWorld(GUI::World *world)
{
    _world = world;
}
