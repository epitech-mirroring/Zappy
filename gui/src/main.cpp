/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** GUI-main
*/

#include <iostream>
#include "handle_args/HandleArgs.hpp"

using namespace GUI;

int main(int ac, char **av)
{
    GUI::HandleArgs args;
    try {
        args.checkArgs(ac, av);
    } catch (const GUI::ArgsException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
