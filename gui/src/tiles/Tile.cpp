/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#include "Tile.hpp"

using namespace GUI;

Tile::Tile(Position pos)
    : _pos(pos)
{
}

Position Tile::getPosition() const
{
    return _pos;
}

void Tile::addObject(IObject *object)
{
    _objects.push_back(object);
}

void Tile::removeObject(IObject *object)
{
    _objects.remove(object);
}

std::list<IObject *> Tile::getObjects() const
{
    return _objects;
}
