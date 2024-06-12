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
    #include "network/command/msz/CommandMapSize.hpp"
    #include "network/command/msz/CommandMapSizeResponse.hpp"
    #include "network/command/bct/CommandBct.hpp"
    #include "network/command/bct/CommandBctReceive.hpp"
    #include "network/command/tna/CommandTna.hpp"
    #include "network/command/tna/CommandTnaReceive.hpp"
    #include <network/command/interface/IWorldCommand.hpp>

namespace network {
    class CommandFactory {
    public:
        /**
         * @brief Construct a new Command Factory object
         */
        CommandFactory(GUI::World &world, GUI::Teams &teams);
        /**
         * @brief Destroy the Command Factory object
         */
        ~CommandFactory() = default;

        /**
         * @brief Get the Command object
         * @param commandName (name of the command)
         */
        [[nodiscard]] std::unique_ptr<ICommand> getCommand(const std::string &commandName);
        /**
         * @brief Get the Response Command object
         * @param responseName (name of the response)
         */
        [[nodiscard]] std::unique_ptr<ICommand> getResponseCommand(const
            std::string &responseName);

    protected:
        std::unordered_map<std::string, std::unique_ptr<ICommand>> _commands;   // Commands map
        std::unordered_map<std::string, std::unique_ptr<ICommand>>              // Response commands map (what the server sends)
            _responseCommands;
    };
} // namespace network //
#endif /* !COMMANDFACTORY_HPP_ */
