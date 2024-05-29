/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** ArgsException
*/

#include "ArgsException.hpp"

using namespace GUI;

ArgsException::ArgsException(const std::string &message)
    : AException{message, "ArgsException"}
{
}
