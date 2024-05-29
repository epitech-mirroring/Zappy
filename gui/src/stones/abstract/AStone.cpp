/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** AStone
*/

#include "AStone.hpp"

using namespace GUI;

AStone::AStone(float density)
    : _density(density)
{
}

float AStone::getDensity() const noexcept
{
    return _density;
}
