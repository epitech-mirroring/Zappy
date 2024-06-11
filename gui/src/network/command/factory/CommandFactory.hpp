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
    #include "network/command/CommandMapSizeResponse.hpp"

namespace network {
    class CommandFactory {
    public:
        /**
         * @brief Construct a new Command Factory object
         */
        CommandFactory();
        /**
         * @brief Destroy the Command Factory object
         */
        ~CommandFactory() = default;

        /**
         * @brief Get the Command object
         * @param commandName (name of the command)
         */
        std::unique_ptr<ICommand> getCommand(const std::string &commandName);
        /**
         * @brief Get the Response Command object
         * @param responseName (name of the response)
         */
        std::unique_ptr<ICommand> getResponseCommand(const
            std::string &responseName);

    protected:
        std::unordered_map<std::string, std::unique_ptr<ICommand>> _commands;   // Commands map
        std::unordered_map<std::string, std::unique_ptr<ICommand>>              // Response commands map (what the server sends)
            _responseCommands;
    };
} // namespace network //
#endif /* !COMMANDFACTORY_HPP_ */
