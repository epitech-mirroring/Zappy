/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSGT
*/

#ifndef COMMANDSGT_HPP_
    #define COMMANDSGT_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandSGT : public ICommand {
    public:
        /**
         * @brief Construct a new CommandSGT object
         */
        CommandSGT() = default;
        /**
         * @brief Destroy the CommandSGT object
         */
        ~CommandSGT() = default;

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
#endif /* !COMMANDSGT_HPP_ */
