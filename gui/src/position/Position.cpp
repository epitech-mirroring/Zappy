/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Position
*/

#include "Position.hpp"

using namespace GUI;

Position::Position(unsigned int x, unsigned int y)
    :   _x(x)
    ,   _y(y)
{
}

Position::~Position()
{
}

unsigned int Position::getX() const noexcept
{
    return _x;
}

unsigned int Position::getY() const noexcept
{
    return _y;
}

void Position::setX(unsigned int x) noexcept
{
    _x = x;
}

void Position::setY(unsigned int y) noexcept
{
    _y = y;
}
