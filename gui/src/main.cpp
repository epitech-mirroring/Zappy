/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include <iostream>
#include "handle_args/HandleArgs.hpp"
#include "game/Game.hpp"

using namespace GUI;

int main(int ac, char **av)
{
    GUI::HandleArgs args;

    if (args.checkArgs(ac, av))
        return 84;
    try {
        GUI::Game game(args.getHostname(), args.getPort());
        game.initGame();
        game.runGame();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
