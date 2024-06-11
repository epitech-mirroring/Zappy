/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include <iostream>
#include "handle_args/HandleArgs.hpp"
#include "display/Window.hpp"

using namespace GUI;

int main(int ac, char **av)
{
    GUI::HandleArgs args;
    GUI::Window win;

    if (args.checkArgs(ac, av))
        return 84;
    win.displayWindow();
    return 0;
}
