/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#include "MockEgg.hpp"

using namespace GUI;

MockEgg::MockEgg(std::string teamName, std::string ownerID, Position tile)
    :   AObject(0, tile)
    ,   _teamName(std::move(teamName))
    ,   _ownerID(ownerID)
{
    _position = tile;
}

MockEgg::~MockEgg()
{
}

std::string MockEgg::getTeam() const
{
    return _teamName;
}

std::string MockEgg::getOwnerID() const
{
    return _ownerID;
}

bool MockEgg::getIsEjected() const
{
    return _isEjected;
}

void MockEgg::setIsEjected(bool isEjected)
{
    _isEjected = isEjected;
}

void MockEgg::setPosition(int x, int y)
{
    _position.setX(x);
    _position.setY(y);
}

Position& MockEgg::getPosition() noexcept
{
    return _position;
}
