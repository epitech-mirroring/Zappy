/*
** File description:
** AException
*/

#include "AException.hpp"

using namespace GUI;

AException::AException(const std::string &message,
    const std::string &type) noexcept
    : _message{std::move(message)}, _type{std::move(type)}
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
