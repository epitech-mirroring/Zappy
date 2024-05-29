/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Phiras
*/

#include "Phiras.hpp"

using namespace GUI;

Phiras::Phiras()
    :   AStone(0.08)
{
}

float Phiras::getDensity() const noexcept
{
    return _density;
}
