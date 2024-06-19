/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Deraumere
*/

#include "Deraumere.hpp"

using namespace GUI;

Deraumere::Deraumere(Position tile)
    :   AStone(1, tile)
{
}

unsigned int Deraumere::getType() noexcept
{
    return 2;
}

std::string Deraumere::getName() const noexcept
{
    return "Deraumere";
}
