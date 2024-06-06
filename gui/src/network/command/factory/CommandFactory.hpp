/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#ifndef COMMANDFACTORY_HPP_
    #define COMMANDFACTORY_HPP_

    #include <memory>
    #include <iostream>
    #include <unordered_map>
    #include "network/command/interface/ICommand.hpp"
    #include "network/command/CommandMapSize.hpp"

namespace network {
    class CommandFactory {
    public:
        CommandFactory();
        ~CommandFactory() = default;

        std::unordered_map<std::string, std::unique_ptr<ICommand>> _commands;
    };
} // namespace network //
#endif /* !COMMANDFACTORY_HPP_ */
