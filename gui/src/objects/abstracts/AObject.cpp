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

unsigned int AObject::getType() noexcept
{
    return 999;
}

unsigned int AObject::getQuantity() noexcept
{
    return 0;
}

void AObject::setQuantity(unsigned int quantity) noexcept
{
    _quantity = quantity;
}
