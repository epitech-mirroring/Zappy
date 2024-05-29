/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** AException
*/

#include "AException.hpp"

using namespace GUI;

AException::AException(const std::string &message,
    const std::string &type) noexcept
    : _message{message}, _type{type}
{
}

const char *AException::what() const noexcept
{
    return _message.c_str();
}

std::string AException::getType() const noexcept
{
    return _type;
}
