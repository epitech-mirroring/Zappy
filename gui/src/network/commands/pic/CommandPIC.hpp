/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIC
*/

#ifndef COMMANDPIC_HPP_
    #define COMMANDPIC_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPIC : public ICommand {
    public:
        /**
         * @brief Construct a new CommandPIC object
         */
        CommandPIC() = default;
        /**
         * @brief Destroy the CommandPIC object
         */
        ~CommandPIC() = default;

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
#endif /* !COMMANDPIC_HPP_ */
