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
    try {
        network::Client client(args.getHostname(), args.getPort());
        client.handleConnection();
        client.handleCommunication();
        client.handleDisconnection();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
