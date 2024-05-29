/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Deraumere
*/

#include "Deraumere.hpp"

using namespace GUI;

Deraumere::Deraumere()
    :   AStone(0.15)
{
}

float Deraumere::getDensity() const noexcept
{
    return _density;
}
