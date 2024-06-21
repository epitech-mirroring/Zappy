/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPIE
*/

#ifndef COMMANDPIE_HPP_
    #define COMMANDPIE_HPP_

#include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPIE : public ICommand {
    public:
        /**
         * @brief Construct a new CommandPIE object
         */
        CommandPIE() = default;
        /**
         * @brief Destroy the CommandPIE object
         */
        ~CommandPIE() = default;

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
#endif /* !COMMANDPIE_HPP_ */
