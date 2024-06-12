/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandBctReceive
*/

#include "CommandBctReceive.hpp"
#include "objects/food/Food.hpp"
#include "objects/stones/Linemate.hpp"
#include "objects/stones/Deraumere.hpp"
#include "objects/stones/Sibur.hpp"
#include "objects/stones/Mendiane.hpp"
#include "objects/stones/Phiras.hpp"
#include "objects/stones/Thystame.hpp"

using namespace network;

void CommandBctReceive::execute(std::unique_ptr<ASocket>& socket,
    const std::string& data)
{
    (void)socket;

    std::istringstream responseStream(data);
    std::string commandName;
    unsigned int x, y, q0, q1, q2, q3, q4, q5, q6;

    responseStream >> commandName >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;
    auto& tile = _world->getTileAt(x, y);
    tile.clearObjects();

    for (unsigned int i = 0; i < q0; ++i)
        tile.addObject(new GUI::Food());
    for (unsigned int i = 0; i < q1; ++i)
        tile.addObject(new GUI::Linemate());
    for (unsigned int i = 0; i < q2; ++i)
        tile.addObject(new GUI::Deraumere());
    for (unsigned int i = 0; i < q3; ++i)
        tile.addObject(new GUI::Sibur());
    for (unsigned int i = 0; i < q4; ++i)
        tile.addObject(new GUI::Mendiane());
    for (unsigned int i = 0; i < q5; ++i)
        tile.addObject(new GUI::Phiras());
    for (unsigned int i = 0; i < q6; ++i)
        tile.addObject(new GUI::Thystame());
}

std::unique_ptr<ICommand> CommandBctReceive::clone() const
{
    return std::make_unique<CommandBctReceive>(*this);
}

void CommandBctReceive::linkWorld(GUI::World *world)
{
    _world = world;
}
