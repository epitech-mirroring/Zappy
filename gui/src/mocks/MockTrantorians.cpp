/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MockTrantorians
*/

#include "MockTrantorians.hpp"
#include "MockTeams.hpp"

using namespace GUI;

MockTrantorians::MockTrantorians(std::string id, int x, int y, float oritentation,
    int level, std::string teamName)
        : _id(id), _position(x, y), _level(level),
        _lifetimeRemaining(100), _alive(true), _action(false), _team(nullptr)
{
    if (!teamName.empty()) {
        auto team = MockTeams::getTeamByName(teamName);
        if (team) {
            setTeam(team);
            team->addMockTrantorians(*this);
        }
    }
    if (oritentation == static_cast<float>(NORTH))
        _orientation = 0;
    else if (oritentation == static_cast<float>(EAST))
        _orientation = 90;
    else if (oritentation == static_cast<float>(SOUTH))
        _orientation = 180;
    else if (oritentation == static_cast<float>(WEST))
        _orientation = 270;
    else
        _orientation = 0;
}

void MockTrantorians::setAction(bool action)
{
    _action = action;
}

bool MockTrantorians::getAction()
{
    return _action;
}

void MockTrantorians::setId(std::string id)
{
    _id = id;
}

std::string MockTrantorians::getId()
{
    return _id;
}

void MockTrantorians::setIsAlive(bool alive)
{
    _alive = alive;
}

bool MockTrantorians::getIsAlive()
{
    return _alive;
}

void MockTrantorians::setLevel(int level)
{
    _level = level;
}

int MockTrantorians::getLevel()
{
    return _level;
}

void MockTrantorians::setLifetime(int lifetime)
{
    _lifetimeRemaining = lifetime;
}

int MockTrantorians::getLifetime()
{
    return _lifetimeRemaining;
}

void MockTrantorians::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}

Position MockTrantorians::getPosition()
{
    return _position;
}

void MockTrantorians::setTeam(MockTeams* team)
{
    _team = team;
}

MockTeams* MockTrantorians::getTeam()
{
    return _team;
}

bool MockTrantorians::operator==(const MockTrantorians& other) const
{
    return _position.getX() == other._position.getX() &&
           _position.getY() == other._position.getY() &&
           _team == other._team &&
           _lifetimeRemaining == other._lifetimeRemaining &&
           _alive == other._alive &&
           _action == other._action &&
           _id == other._id &&
           _level == other._level;
           _orientation == other._orientation;
}

void MockTrantorians::setOrientation(float orientation)
{
    _orientation = orientation;
}

float MockTrantorians::getOrientation()
{
    return _orientation;
}

void MockTrantorians::setInventory(std::vector<std::string> inventory)
{
    std::vector<std::string> objects(inventory.begin() + 3, inventory.begin() + 10);

    clearInventory();

    for (int i = 0; i < objects.size(); i++) {
        ResourceType type = static_cast<ResourceType>(i);
        int quantity = std::stoi(objects[i]);
        while (quantity > 0) {
            IObject *object = createObjectByType(type, _position);
            addObject(object);
            quantity--;
        }
        while (quantity < 0) {
            removeObject(_inventory.back());
            quantity++;
        }
    }
}

IObject* MockTrantorians::createObjectByType(ResourceType type, Position pos)
{
    switch (type) {
        case ResourceType::FOOD:
            return new Food(pos);
        case ResourceType::LINEMATE:
            return new Linemate(pos);
        case ResourceType::DERAUMERE:
            return new Deraumere(pos);
        case ResourceType::SIBUR:
            return new Sibur(pos);
        case ResourceType::MENDIANE:
            return new Mendiane(pos);
        case ResourceType::PHIRAS:
            return new Phiras(pos);
        case ResourceType::THYSTAME:
            return new Thystame(pos);
        default:
            return nullptr;
    }
}

void MockTrantorians::clearInventory()
{
    _inventory.clear();
}

void MockTrantorians::addObject(IObject *object)
{
    _inventory.push_back(object);
}

void MockTrantorians::removeObject(IObject *object)
{
    _inventory.remove(object);
}

std::list<IObject*> MockTrantorians::getInventory() const
{
    return _inventory;
}
