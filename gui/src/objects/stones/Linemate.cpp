/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Linemate
*/

#include "Linemate.hpp"

using namespace GUI;

Linemate::Linemate(Position tile)
    :   AStone(1, tile)
{
}

unsigned int Linemate::getType() noexcept
{
    return 1;
}

std::string Linemate::getName() const noexcept
{
    return "Linemate";
}
