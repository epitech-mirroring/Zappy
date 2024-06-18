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

    std::unordered_map<ResourceType, int> currentCounts;
    std::unordered_map<ResourceType, std::list<IObject*>::iterator> objectIterators;

    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        ResourceType type = static_cast<ResourceType>((*it)->getType());
        currentCounts[type]++;
        objectIterators[type] = it;
    }

    for (int i = 0; i < newCounts.size(); ++i) {
        ResourceType type = static_cast<ResourceType>(i);
        int difference = newCounts[i] - currentCounts[type];

        if (difference > 0) {
            for (int j = 0; j < difference; ++j) {
                IObject* object = createObjectByType(type, _pos);
                if (object != nullptr) {
                    _objects.push_back(object);
                }
            }
        } else if (difference < 0) {
            for (int j = 0; j < -difference; ++j) {
                auto it = objectIterators.find(type);
                if (it != objectIterators.end() && it->second != _objects.end()) {
                    delete *(it->second);
                    _objects.erase(it->second);
                    objectIterators.erase(it);
                }
            }
        }
    }
}
