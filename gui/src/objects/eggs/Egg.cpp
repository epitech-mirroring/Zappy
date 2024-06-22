/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#include "Egg.hpp"

using namespace GUI;

Egg::Egg(std::string eggId, std::string ownerID, Position tile)
    :   AObject(0, tile)
    ,   _eggId(std::move(eggId))
    ,   _ownerID(ownerID)
{
    _eggModel = LoadModel("gui/src/assets/egg/egg.obj");
    _eggTexture = LoadTexture("gui/src/assets/egg/egg.png");
    _eggModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _eggTexture;
    _position = tile;
}

Egg::~Egg()
{
}

std::string Egg::getTeam() const
{
    return _teamName;
}

std::string Egg::getEggId() const
{
    return _eggId;
}

std::string Egg::getOwnerID() const
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
