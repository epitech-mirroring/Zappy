/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** HandleArgs
*/

#ifndef HANDLEARGS_HPP_
#define HANDLEARGS_HPP_

#include <string>

#include "exception/ArgsException.hpp"

namespace GUI {
class HandleArgs {
    public:
        HandleArgs() = default;
        ~HandleArgs() = default;

        int checkArgs(int nbArgs, char **args);
        int checkPort(const std::string &port);
        int checkHostname(const std::string &hostname);

        void printUsage();
    protected:
        unsigned int _port;
        std::string _hostname;
};
} // namespace GUI //
#endif /* !HANDLEARGS_HPP_ */
