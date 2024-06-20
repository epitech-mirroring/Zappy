/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Teams
*/

#include "Teams.hpp"

using namespace GUI;

std::list<GUI::Teams> Teams::_teams;

Teams::Teams(std::string name)
    : _name(std::move(name))
{
}

void Teams::setName(std::string name)
{
    _name = std::move(name);
}

std::string Teams::getName() const
{
    return _name;
}

void Teams::addTrantorian(Trantorian& trantorian)
{
    if (!hasTrantorian(trantorian.getId())) {
        _trantorians.emplace_back(trantorian);
    }
}

std::list<Trantorian> Teams::getTrantorianList() const
{
    return _trantorians;
}

void Teams::addTeamToTeamsList(const Teams& team)
{
    for (const auto& existingTeam : _teams) {
        if (existingTeam.getName() == team.getName()) {
            return;
        }
    }
    _teams.emplace_back(team);
}

std::list<Teams>& Teams::getTeamsList()
{
    return _teams;
}

Teams* Teams::getTeamByName(const std::string& name)
{
    for (auto &team : _teams) {
        if (team.getName() == name)
            return &team;
    }
    return nullptr;
}

Trantorian Teams::getTrantorianById(std::string id)
{
    for (auto &trantorian : _trantorians) {
        if (trantorian.getId() == id)
            return trantorian;
    }
    return Trantorian();
}

bool Teams::hasTrantorian(const std::string& id) const
{
    for (const auto& trantorian : _trantorians) {
        if (trantorian.getId() == id) {
            return true;
        }
    }
    return false;
}

std::list<Egg> Teams::getEggList() const
{
    return _eggs;
}
