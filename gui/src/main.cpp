/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** main
*/

#include <iostream>
#include "handle_args/HandleArgs.hpp"
#include "network/client/Client.hpp"

int main(int ac, char **av)
{
    GUI::HandleArgs args;

    if (args.checkArgs(ac, av))
        return 84;

    network::Client client(args.getHostname(), args.getPort());

    try {
        client.handleConnection();
    } catch (const std::exception &e) {
        client.handleDisconnection();
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
