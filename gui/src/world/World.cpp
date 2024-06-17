/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** World
*/

#include "World.hpp"

using namespace GUI;

World::World(unsigned int width, unsigned int height)
    : _width(width), _height(height)
{
    setWorldSize(width, height);
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

void World::addObject(IObject *object, Position pos)
{
    if (pos.getX() < _width && pos.getY() < _height) {
        _tiles[pos.getX()][pos.getY()].addObject(object);
    }
}

void World::removeObject(IObject *object, Position pos)
{
    if (pos.getX() < _width && pos.getY() < _height) {
        _tiles[pos.getX()][pos.getY()].removeObject(object);
    }
}

std::list<IObject *> World::getObjects() const
{
    std::list<IObject *> objects;
    for (const auto& row : _tiles) {
        for (const auto& tile : row) {
            auto tileObjects = tile.getObjects();
            objects.insert(objects.end(), tileObjects.begin(), tileObjects.end());
        }
    }
    return objects;
}

std::list<IObject *> World::getObjectsAt(Position tile) const
{
    if (tile.getX() < _width && tile.getY() < _height) {
        return _tiles[tile.getX()][tile.getY()].getObjects();
    }
    return {};
}

void World::setWorldSize(unsigned int width, unsigned int height)
{
    _width = width;
    _height = height;
    _tiles.resize(width);

    for (unsigned int i = 0; i < width; ++i) {
        _tiles[i].resize(height, Tile(Position(i, 0)));
        for (unsigned int j = 0; j < height; ++j) {
            _tiles[i][j] = Tile(Position(i, j));
        }
    }
}

std::vector<std::vector<Tile>>& World::getTiles()
{
    return _tiles;
}

Tile& World::getTileAt(unsigned int x, unsigned int y)
{
    return _tiles[x][y];
}

void World::addTile(Tile tile)
{
    _tiles[tile.getPosition().getX()][tile.getPosition().getY()] = tile;
}
