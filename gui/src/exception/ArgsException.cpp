/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ArgsException
*/

#include "ArgsException.hpp"

using namespace GUI;

ArgsException::ArgsException(std::string message)
    : AException{std::move(message), "ArgsException"}
{
}
