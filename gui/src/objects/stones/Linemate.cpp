/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Linemate
*/

#include "Linemate.hpp"

using namespace GUI;

Linemate::Linemate(Position tile)
    :   AStone(0.3, tile)
{
}

unsigned int Linemate::getType() noexcept
{
    return 1;
}
