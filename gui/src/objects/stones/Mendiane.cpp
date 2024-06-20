/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Mendiane
*/

#include "Mendiane.hpp"

using namespace GUI;

Mendiane::Mendiane(Position tile)
    :   AStone(1, tile)
{
}

unsigned int Mendiane::getType() noexcept
{
    return 4;
}

std::string Mendiane::getName() const noexcept
{
    return "Mendiane";
}
