/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Teams
*/

#include "Teams.hpp"

GUI::Teams::Teams(std::string name)
    :   _name(name)
{
}

void GUI::Teams::setName(std::string name)
{
    _name = name;
}

std::string GUI::Teams::getName()
{
    return _name;
}

void GUI::Teams::addTrantorian(GUI::Trantorian trantorian)
{
    _trantorians.emplace_back(trantorian);
}

std::list<GUI::Trantorian> GUI::Teams::getTrantorianList()
{
    return _trantorians;
}
