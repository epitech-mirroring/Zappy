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

std::string Linemate::getType() const noexcept
{
    return "Linemate";
}
