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

void Tile::clearObjects()
{
    _objects.clear();
}

IObject* Tile::createObjectByType(ResourceType type, Position pos)
{
    switch (type) {
        case FOOD: return new Food(pos);
        case LINEMATE: return new Linemate(pos);
        case DERAUMERE: return new Deraumere(pos);
        case SIBUR: return new Sibur(pos);
        case MENDIANE: return new Mendiane(pos);
        case PHIRAS: return new Phiras(pos);
        case THYSTAME: return new Thystame(pos);
        default: return nullptr;
    }
}

void Tile::updateTileContent(std::vector<std::string> tileContent)
{
    std::vector<std::string> objects(tileContent.begin() + 2, tileContent.begin() + 9);

    clearObjects();

    for (int i = 0; i < objects.size(); i++) {
        ResourceType type = static_cast<ResourceType>(i);
        int quantity = std::stoi(objects[i]);
        while (quantity > 0) {
            IObject *object = createObjectByType(type, _pos);
            addObject(object);
            quantity--;
        }
        while (quantity < 0) {
            removeObject(_objects.back());
            quantity++;
        }
    }
}
