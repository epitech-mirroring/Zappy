/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AObject
*/

#include "AObject.hpp"

using namespace GUI;

AObject::AObject(unsigned int quantity, Position tile)
    : _quantity(quantity)
    , _position(tile)
{
}

unsigned int AObject::getQuantity() const noexcept
{
    return _quantity;
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

void AObject::setQuantity(unsigned int quantity) noexcept
{
    _quantity = quantity;
}

std::string AObject::getName() const noexcept
{
    return "null";
}
