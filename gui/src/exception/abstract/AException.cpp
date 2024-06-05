/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AException
*/

#include "AException.hpp"

using namespace zappy;

AException::AException(std::string message, std::string type) noexcept
    : _message{std::move(message)}
    , _type{std::move(type)}
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
