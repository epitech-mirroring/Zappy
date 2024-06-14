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

void Tile::updateTileContent(std::string tileContent)
{
    std::istringstream iss(tileContent);
    std::vector<int> desiredQuantities;
    std::string token;

    while (std::getline(iss, token, ' '))
        desiredQuantities.push_back(std::stoi(token));

    std::unordered_map<ResourceType, int> currentQuantities;

    for (auto& obj : _objects)
        currentQuantities[static_cast<ResourceType>(obj->getType())]++;

    for (int type = 0; type < RESOURCE_COUNT; ++type) {
        ResourceType resourceType = static_cast<ResourceType>(type);
        int currentQuantity = currentQuantities[resourceType];
        int desiredQuantity = desiredQuantities[type];

        if (currentQuantity < desiredQuantity) {
            for (int i = 0; i < desiredQuantity - currentQuantity; ++i)
                addObject(createObjectByType(resourceType, _pos));
        } else if (currentQuantity > desiredQuantity) {
            auto it = _objects.begin();
            while (currentQuantity > desiredQuantity && it != _objects.end()) {
                if ((*it)->getType() == type) {
                    delete *it;
                    it = _objects.erase(it);
                    currentQuantity--;
                } else {
                    ++it;
                }
            }
        }
    }
}
