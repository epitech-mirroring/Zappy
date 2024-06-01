/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#include "Egg.hpp"

using namespace GUI;

Egg::Egg(std::string teamName, int ownerID)
    :   AObject(0)
    ,   _teamName(std::move(teamName))
    ,   _ownerID(ownerID)
{
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
