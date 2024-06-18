/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Trantorian
*/

#include "Trantorian.hpp"
#include "Teams.hpp"

using namespace GUI;

Trantorian::Trantorian(std::string id, int x, int y, int oritentation,
    int level, std::string teamName)
        : _id(id), _position(x, y), _orientation(oritentation), _level(level),
        _lifetimeRemaining(100), _alive(true), _action(false), _team(nullptr)
{
    if (!teamName.empty()) {
        auto team = Teams::getTeamByName(teamName);
        if (team) {
            setTeam(team);
            team->addTrantorian(*this);
        }
    }
    _trantorianModel = LoadModel("gui/src/assets/trantorian/trantorian.obj");
    _trantorianTexture = LoadTexture("gui/src/assets/trantorian/trantorian.png");
    _trantorianModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _trantorianTexture;
}

void Trantorian::setAction(bool action)
{
    _action = action;
}

bool Trantorian::getAction()
{
    return _action;
}

void Trantorian::setId(std::string id)
{
    _id = id;
}

std::string Trantorian::getId()
{
    return _id;
}

void Trantorian::setIsAlive(bool alive)
{
    _alive = alive;
}

bool Trantorian::getIsAlive()
{
    return _alive;
}

void Trantorian::setLevel(int level)
{
    _level = level;
}

int Trantorian::getLevel()
{
    return _level;
}

void Trantorian::setLifetime(int lifetime)
{
    _lifetimeRemaining = lifetime;
}

int Trantorian::getLifetime()
{
    return _lifetimeRemaining;
}

void Trantorian::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}

Position Trantorian::getPosition()
{
    return _position;
}

void Trantorian::setTeam(Teams* team)
{
    _team = team;
}

Teams* Trantorian::getTeam()
{
    return _team;
}

bool Trantorian::operator==(const Trantorian& other) const
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

void Trantorian::setOrientation(int orientation)
{
    _orientation = orientation;
}

void Trantorian::setInventory(std::vector<std::string> inventory)
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

IObject* Trantorian::createObjectByType(ResourceType type, Position pos)
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

void Trantorian::clearInventory()
{
    _inventory.clear();
}

void Trantorian::addObject(IObject *object)
{
    _inventory.push_back(object);
}

void Trantorian::removeObject(IObject *object)
{
    _inventory.remove(object);
}

std::list<IObject*> Trantorian::getInventory() const
{
    return _inventory;
}

Model Trantorian::getModel() const
{
    return _trantorianModel;
}

Texture2D Trantorian::getTexture() const
{
    return _trantorianTexture;
}
