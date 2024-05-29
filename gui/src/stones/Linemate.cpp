/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Linemate
*/

#include "Linemate.hpp"

using namespace GUI;

Linemate::Linemate()
    :   AStone(0.3)
{
}

float Linemate::getDensity() const noexcept
{
    return _density;
}
