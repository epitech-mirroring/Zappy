/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPGT
*/

#ifndef COMMANDPGT_HPP_
    #define COMMANDPGT_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPGT : public ICommand {
    public:
        /**
         * @brief Construct a new Command PGT object
         */
        CommandPGT() = default;
        /**
         * @brief Destroy the Command PGT object
         */
        ~CommandPGT() = default;

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
#endif /* !COMMANDPGT_HPP_ */
