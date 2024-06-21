/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ClientException
*/

#include "ClientException.hpp"

using namespace network;

ClientException::ClientException(std::string message)
    : AException{std::move(message), "ClientException"}
{
}
