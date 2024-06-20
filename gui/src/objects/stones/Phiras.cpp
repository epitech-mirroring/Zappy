/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Phiras
*/

#include "Phiras.hpp"

using namespace GUI;

Phiras::Phiras(Position tile)
    :   AStone(1, tile)
{
}

unsigned int Phiras::getType() noexcept
{
    return 5;
}

std::string Phiras::getName() const noexcept
{
    return "Phiras";
}
