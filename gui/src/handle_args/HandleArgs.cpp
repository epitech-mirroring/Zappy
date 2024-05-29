/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** HandleArgs
*/

#include "HandleArgs.hpp"
#include <iostream>

using namespace GUI;

int HandleArgs::checkArgs(int nbArgs, char **args)
{
    try {
        if (nbArgs == 2 &&
            (std::string(args[1]) == "-help" || std::string(args[1]) == "-h")) {
            printUsage();
            goto end;
        }
        if (nbArgs != 3)
            throw ArgsException("ARGS ERROR: Invalid number of arguments");
        if (checkPort(args[1]) == 84)
            throw ArgsException("ARGS ERROR: Invalid port");
        if (checkHostname(args[2]) == 84)
            throw ArgsException("ARGS ERROR: Invalid hostname");
    } catch (const ArgsException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    end:
    return 0;
}

void HandleArgs::printUsage()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
}

int HandleArgs::checkPort(const std::string &port)
{
    for (const auto &c : port) {
        if (!std::isdigit(c))
            return 84;
    }
    int tmp = std::stoi(port);
    if (tmp < 0 || tmp > 65535)
        return 84;
    _port = tmp;
    return 0;
}

int HandleArgs::checkHostname(const std::string &hostname)
{
    _hostname = hostname;
    return 0;
}
