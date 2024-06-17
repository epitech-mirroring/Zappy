/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Mendiane
*/

#include "Mendiane.hpp"

using namespace GUI;

Mendiane::Mendiane(Position tile)
    :   AStone(0.1, tile)
{
}

unsigned int Mendiane::getType() noexcept
{
    return 4;
}
