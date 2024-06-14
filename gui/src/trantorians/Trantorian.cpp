/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Trantorian
*/

#include "Trantorian.hpp"
#include "Teams.hpp"

GUI::Trantorian::Trantorian(std::string teamName, int x, int y)
    : _team(nullptr)
{
    setPosition(x, y);
    _alive = true;
    _action = false;
    _level = 1;
    _lifetimeRemaining = 100;

    if (!teamName.empty()) {
        auto team = Teams::getTeamByName(teamName);
        if (team) {
            setTeam(team);
            team->addTrantorian(*this);
        }
    }
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
    _position.setX(x);
    _position.setY(y);
}

GUI::Position GUI::Trantorian::getPosition()
{
    return _position;
}

void GUI::Trantorian::setTeam(Teams* team)
{
    _team = team;
}

GUI::Teams* GUI::Trantorian::getTeam()
{
    return _team;
}

bool GUI::Trantorian::operator==(const Trantorian& other) const
{
    return _position.getX() == other._position.getX() &&
           _position.getY() == other._position.getY() &&
           _team == other._team &&
           _lifetimeRemaining == other._lifetimeRemaining &&
           _alive == other._alive &&
           _action == other._action &&
           _id == other._id &&
           _level == other._level;
}
