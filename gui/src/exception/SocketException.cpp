/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SocketException
*/

#include "SocketException.hpp"

using namespace zappy;

SocketException::SocketException(std::string message)
    : AException{std::move(message), "SocketException"}
{
}
