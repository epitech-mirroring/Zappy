/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** HandleArgs
*/

#include "HandleArgs.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace GUI;

int HandleArgs::checkArgs(int nbArgs, char **args)
{
    try {
        if (nbArgs == 2 &&
            (std::string(args[1]) == "--help" || std::string(args[1]) == "-h")) {
            printUsage();
            return 0;
        }
        if (nbArgs != 3)
            throw zappy::ArgsException("ARGS ERROR: Invalid number of arguments");
        if (checkPort(args[1]) == 84)
            throw zappy::ArgsException("ARGS ERROR: Invalid port");
        if (checkHostname(args[2]) == 84)
            throw zappy::ArgsException("ARGS ERROR: Invalid hostname");
    } catch (const zappy::ArgsException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
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
    std::vector<std::string> parts;
    std::stringstream ss(hostname);
    std::string part;

    while (std::getline(ss, part, '.'))
        parts.push_back(part);
    if (parts.size() != 4)
        return 84;
    for (const auto &p : parts) {
        if (p.empty() || p.size() > 3)
            return 84;
        for (const auto &c : p) {
            if (!std::isdigit(c))
                return 84;
        }
        int num = std::stoi(p);
        if (num < 0 || num > 255)
            return 84;
    }
    _hostname = hostname;
    return 0;
}
