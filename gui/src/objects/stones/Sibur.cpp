/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Sibur
*/

#include "Sibur.hpp"

using namespace GUI;

Sibur::Sibur(Position tile)
    :   AStone(1, tile)
{
}

unsigned int Sibur::getType() noexcept
{
    return 3;
}

std::string Sibur::getName() const noexcept
{
    return "Sibur";
}
