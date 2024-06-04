/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AObject
*/

#include "AObject.hpp"

using namespace GUI;

AObject::AObject(float density)
    : _density(density)
{
}

float AObject::getDensity() const noexcept
{
    return _density;
}