/*
** File description:
** Tribes
*/

#include "Tribes.hpp"

GUI::Tribes::Tribes(std::string name)
    :   _name(name)
{
}

void GUI::Tribes::setName(std::string name)
{
    _name = name;
}

std::string GUI::Tribes::getName()
{
    return _name;
}

void GUI::Tribes::addTrantorian(GUI::Trantorian trantorian)
{
    _trantorians.emplace_back(trantorian);
}

std::list<GUI::Trantorian> GUI::Tribes::getTrantorianList()
{
    return _trantorians;
}
