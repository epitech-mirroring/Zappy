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

    args.checkArgs(ac, av);
    return 0;
}
