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

std::string Deraumere::getType() const noexcept
{
    return "Deraumere";
}
