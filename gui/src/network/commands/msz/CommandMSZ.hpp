/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMSZ
*/

#ifndef COMMANDMSZ_HPP_
    #define COMMANDMSZ_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandMSZ : public ICommand {
    public:
        /**
         * @brief Construct a new Command PPO object
         */
        CommandMSZ() = default;
        /**
         * @brief Destroy the Command PPO object
         */
        ~CommandMSZ() = default;

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
#endif /* !COMMANDMSZ_HPP_ */
