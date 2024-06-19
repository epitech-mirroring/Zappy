/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Thystame
*/

#include "Thystame.hpp"

using namespace GUI;

Thystame::Thystame(Position tile)
    :   AStone(1, tile)
{
}

unsigned int Thystame::getType() noexcept
{
    return 6;
}

std::string Thystame::getName() const noexcept
{
    return "Thystame";
}
