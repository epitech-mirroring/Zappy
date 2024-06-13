/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** SocketException
*/

#include "SocketException.hpp"

using namespace network;

SocketException::SocketException(std::string message)
    : AException{std::move(message), "SocketException"}
{
}
