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
        if (nbArgs == 2 && std::string(args[1]) == "--help") {
            printUsage();
            exit (0);
        }
        if (nbArgs != 5)
            throw GUI::ArgsException("ARGS ERROR: Invalid number of arguments");

        std::string port;
        std::string hostname;

        for (int i = 1; i < nbArgs; i += 2) {
            std::string arg(args[i]);
            if (arg == "-p")
                port = std::string(args[i + 1]);
            else if (arg == "-h")
                hostname = std::string(args[i + 1]);
            else
                throw GUI::ArgsException("ARGS ERROR: Invalid argument");
        }
        if (port.empty() || hostname.empty())
            throw GUI::ArgsException("ARGS ERROR: Missing port or hostname");
        if (checkPort(port) == 84)
            throw GUI::ArgsException("ARGS ERROR: Invalid port");
        if (checkHostname(hostname) == 84)
            throw GUI::ArgsException("ARGS ERROR: Invalid hostname");
    } catch (const GUI::ArgsException &e) {
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

unsigned int HandleArgs::getPort() const
{
    return _port;
}

std::string HandleArgs::getHostname() const
{
    return _hostname;
}
