/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ArgsException
*/

#include "ArgsException.hpp"

using namespace zappy;

ArgsException::ArgsException(std::string message)
    : AException{std::move(message), "ArgsException"}
{
}
