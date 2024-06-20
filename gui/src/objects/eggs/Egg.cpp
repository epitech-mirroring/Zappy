/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#include "Egg.hpp"

using namespace GUI;

Egg::Egg(std::string teamName, int ownerID, Position tile)
    :   AObject(0, tile)
    ,   _teamName(std::move(teamName))
    ,   _ownerID(ownerID)
{
    _eggModel = LoadModel("gui/src/assets/egg/egg.obj");
}

Egg::~Egg()
{
}

std::string Egg::getTeam() const
{
    return _teamName;
}

int Egg::getOwnerID() const
{
    return _ownerID;
}

bool Egg::getIsEjected() const
{
    return _isEjected;
}

void Egg::setIsEjected(bool isEjected)
{
    _isEjected = isEjected;
}

void Egg::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}

Position& Egg::getPosition() noexcept
{
    return _position;
}

Model Egg::getModel()
{
    return _eggModel;
}
