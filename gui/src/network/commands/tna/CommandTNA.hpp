/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTNA
*/

#ifndef COMMANDTNA_HPP_
    #define COMMANDTNA_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandTNA : public ICommand {
    public:
        /**
         * @brief Construct a new Command TNA object
         */
        CommandTNA() = default;
        /**
         * @brief Destroy the Command TNA object
         */
        ~CommandTNA() = default;

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
#endif /* !COMMANDTNA_HPP_ */
