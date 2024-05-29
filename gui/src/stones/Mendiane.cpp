/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Mendiane
*/

#include "Mendiane.hpp"

using namespace GUI;

Mendiane::Mendiane()
    :   AStone(0.1)
{
}

Mendiane::~Mendiane()
{
}

float Mendiane::getDensity() const noexcept
{
    return _density;
}
