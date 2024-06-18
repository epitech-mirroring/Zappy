/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Phiras
*/

#include "Phiras.hpp"

using namespace GUI;

Phiras::Phiras(Position tile)
    :   AStone(0.08, tile)
{
}

unsigned int Phiras::getType() noexcept
{
    return 5;
}
