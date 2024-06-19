/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Food
*/

#include "Food.hpp"

using namespace GUI;

Food::Food(Position tile)
    :   AObject(1, tile)
{
}

unsigned int Food::getType() noexcept
{
    return 0;
}

std::string Food::getName() const noexcept
{
    return "Food";
}
