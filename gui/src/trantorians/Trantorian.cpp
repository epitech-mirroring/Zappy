/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Trantorian
*/

#include "Trantorian.hpp"

GUI::Trantorian::Trantorian()
{
}

GUI::Trantorian::~Trantorian()
{
}

void GUI::Trantorian::setAction(bool action)
{
    _action = action;
}

bool GUI::Trantorian::getAction()
{
    return _action;
}

void GUI::Trantorian::setId(int id)
{
    _id = id;
}

int GUI::Trantorian::getId()
{
    return _id;
}

void GUI::Trantorian::setIsAlive(bool alive)
{
    _alive = alive;
}

bool GUI::Trantorian::getIsAlive()
{
    return _alive;
}

void GUI::Trantorian::setLevel(int level)
{
    _level = level;
}

int GUI::Trantorian::getLevel()
{
    return _level;
}

void GUI::Trantorian::setLifetime(int lifetime)
{
    _lifetimeRemaining = lifetime;
}

int GUI::Trantorian::getLifetime()
{
    return _lifetimeRemaining;
}

void GUI::Trantorian::setPosition(int x, int y)
{
    _postion = {x, y};
}

std::vector<int, int> GUI::Trantorian::getPosition()
{
    return _postion;
}

void GUI::Trantorian::setTeam(std::string teamName)
{
    _team = teamName;
}

std::string GUI::Trantorian::getTeam()
{
    return _team;
}
