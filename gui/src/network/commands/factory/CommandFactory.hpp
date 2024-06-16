/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#ifndef COMMANDFACTORY_HPP_
    #define COMMANDFACTORY_HPP_

    #include "network/commands/bct/CommandBCT.hpp"
    #include "network/commands/tna/CommandTNA.hpp"
    #include "network/commands/pnw/CommandPNW.hpp"
    #include "network/commands/ppo/CommandPPO.hpp"

    #include "network/commands/interface/ICommand.hpp"
    #include <unordered_map>
    #include <string>
    #include <memory>

namespace network {
    class CommandFactory : public ICommand {
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
         * @brief Execute the command
         * @param std::string commandName, name of the command to create
         * @return std::unique_ptr<ICommand> the created command
         */
        std::unique_ptr<ICommand> createCommand(const std::string& commandName);

        /**
         * @brief Execute the command
         * @param std::string &commandName, name of the command to create
         * @param Callback callback, the callback to attach to the command
         */
        void setCallback(const std::string& commandName,
            ICommand::Callback callback);

        /**
         * @brief Execute the command
         * @param std::istringstream &iss, the command to execute
         */
        void execute(std::istringstream& iss) override;

        /**
         * @brief Clone the command
         */
        std::unique_ptr<ICommand> clone() const override;

    private:
        std::unordered_map<std::string,
            std::unique_ptr<ICommand>> _commands;
        std::unordered_map<std::string,
            ICommand::Callback> _callbacks;
    };
} // namespace network //
#endif /* !COMMANDFACTORY_HPP_ */
