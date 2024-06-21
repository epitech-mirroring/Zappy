/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPPO
*/

#ifndef COMMANDPPO_HPP_
    #define COMMANDPPO_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPPO : public ICommand {
    public:
        /**
         * @brief Construct a new Command PPO object
         */
        CommandPPO() = default;
        /**
         * @brief Destroy the Command PPO object
         */
        ~CommandPPO() = default;

        /**
         * @brief Execute the command by callback
         * @param iss std::istringstream
         */
        void execute(std::istringstream &iss) final;
        /**
         * @brief Clone the command
         * @return std::unique_ptr<ICommand>
         */
        std::unique_ptr<ICommand> clone() const final;
    };
} // namespace network //
#endif /* !COMMANDPPO_HPP_ */
