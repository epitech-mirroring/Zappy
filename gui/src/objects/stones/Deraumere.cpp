/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Deraumere
*/

#include "Deraumere.hpp"

using namespace GUI;

Deraumere::Deraumere(Position tile)
    :   AStone(0.15, tile)
{
}

unsigned int Deraumere::getType() noexcept
{
    return 2;
}
