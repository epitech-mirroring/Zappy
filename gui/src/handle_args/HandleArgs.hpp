/*
** EPITECH PROJECT, 2024
** Zappy
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
        /**
         * @brief Construct a new HandleArgs object
         */
        HandleArgs() = default;
        /**
         * @brief Destroy the HandleArgs object
         */
        ~HandleArgs() = default;

        /**
         * @brief Check if the given args are valid
         * @param nbArgs (number of arguments)
         * @param args (arguments)
         * @return 0 if the args are valid, 84 if not (and throw an exception)
         */
        [[nodiscard]] int checkArgs(int nbArgs, char **args);
        /**
         * @brief Get the Port object
         * @param port (port given as argument)
         * @return int, 0 if the port is valid, 84 if not
         */
        [[nodiscard]] int checkPort(const std::string &port);
        /**
         * @brief Check if the Hostname given as argument is valid
         * @param hostname (hostname given as argument)
         * @return int, 0 if the hostname is valid, 84 if not
        */
        [[nodiscard]] int checkHostname(const std::string &hostname);

        /**
         * @brief Print the usage of the program
         * @return void (nothing to return)
         */
        void printUsage();
    protected:
        unsigned int _port;         // port of the server
        std::string _hostname;      // hostname of the server
    };
} // namespace GUI //
#endif /* !HANDLEARGS_HPP_ */
