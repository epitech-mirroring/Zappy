/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Food
*/

#include "Food.hpp"

using namespace GUI;

Food::Food(Position tile)
    :   AObject(0.5, tile)
{
}

std::string Food::getType() const noexcept
{
    return "Food";
}
