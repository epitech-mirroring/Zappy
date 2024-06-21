/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPFK
*/

#ifndef COMMANDPFK_HPP_
    #define COMMANDPFK_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPFK : public ICommand {
    public:
        /**
         * @brief Construct a new Command PFK object
         */
        CommandPFK() = default;
        /**
         * @brief Destroy the Command PFK object
         */
        ~CommandPFK() = default;

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
#endif /* !COMMANDPFK_HPP_ */
