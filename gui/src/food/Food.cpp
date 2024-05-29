/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Food
*/

#include "Food.hpp"

using namespace GUI;

Food::Food(float density)
    :   _density(density)
{
}

Food::~Food()
{
}

float Food::getDensity() const noexcept
{
    return _density;
}
