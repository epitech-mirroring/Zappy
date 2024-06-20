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

void Tile::updateTileContent(const std::vector<std::string>& tileContent)
{
    if (tileContent.size() != 7) {
        throw std::runtime_error("Invalid tile content size");
    }

    std::vector<int> newCounts(ResourceType::RESOURCE_COUNT, 0);

    for (size_t i = 0; i < 7; ++i) {
        newCounts[i] = std::stoi(tileContent[i]);
    }

    std::unordered_map<ResourceType, IObject*> objectMap;

    for (auto& object : _objects) {
        ResourceType type = static_cast<ResourceType>(object->getType());
        objectMap[type] = object;
    }

    for (int i = 0; i < newCounts.size(); ++i) {
        ResourceType type = static_cast<ResourceType>(i);
        int newQuantity = newCounts[i];

        if (objectMap.find(type) != objectMap.end()) {
            IObject* object = objectMap[type];
            if (newQuantity > 0) {
                object->setQuantity(newQuantity);
            } else {
                removeObject(object);
                delete object;
            }
        } else {
            if (newQuantity > 0) {
                IObject* object = createObjectByType(type, _pos);
                if (object != nullptr) {
                    object->setQuantity(newQuantity);
                    addObject(object);
                }
            }
        }
    }
}
