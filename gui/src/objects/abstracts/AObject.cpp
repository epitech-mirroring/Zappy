/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AObject
*/

#include "AObject.hpp"

using namespace GUI;

AObject::AObject(float density, Position tile)
    : _density(density)
    , _position(tile)
{
}

float AObject::getDensity() const noexcept
{
    return _density;
}

const Position& AObject::getPosition() const noexcept
{
    return _position;
}

Position& AObject::getPosition() noexcept
{
    return _position;
}

std::string AObject::getType() const noexcept
{
    return "AObject";
}
