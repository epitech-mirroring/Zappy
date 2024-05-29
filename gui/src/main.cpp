/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** GUI-main
*/

#include <iostream>
#include "exception/ArgsException.hpp"

using namespace GUI;

int main(int ac, char **av)
{
    try {
        if (ac != 1)
            throw ArgsException("Invalid number of arguments");
    } catch (const GUI::ArgsException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
