/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** World
*/

#include "World.hpp"

using namespace GUI;

World::World(unsigned int width, unsigned int height)
    :   _width(width)
    ,   _height(height)
{
}

World::~World()
{
}

void World::setWidth(unsigned int width)
{
    _width = width;
}

void World::setHeight(unsigned int height)
{
    _height = height;
}

unsigned int World::getWidth() const
{
    return _width;
}

unsigned int World::getHeight() const
{
    return _height;
}

void World::addObject(IObject *object)
{
    _objects.push_back(object);
}

void World::removeObject(IObject *object)
{
    _objects.remove(object);
}

std::list<IObject *> World::getObjects() const
{
    return _objects;
}

std::list <IObject *> World::getObjectsAt(Position tile) const
{
    std::list<IObject *> objects;

    for (auto object : _objects) {
        if (object->getPosition().getX() == tile.getX() &&
            object->getPosition().getY() == tile.getY()) {
            objects.push_back(object);
        }
    }
}
