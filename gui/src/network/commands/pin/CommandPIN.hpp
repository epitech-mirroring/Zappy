/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIN
*/

#ifndef COMMANDPIN_HPP_
    #define COMMANDPIN_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPIN : public ICommand {
    public:
        /**
         * @brief Construct a new Command PIN object
         */
        CommandPIN() = default;
        /**
         * @brief Destroy the Command PIN object
         */
        ~CommandPIN() = default;

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
#endif /* !COMMANDPIN_HPP_ */
