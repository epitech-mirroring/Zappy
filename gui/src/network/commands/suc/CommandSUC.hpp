/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSUC
*/

#ifndef COMMANDSUC_HPP_
    #define COMMANDSUC_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandSUC : public ICommand {
    public:
        /**
         * @brief Construct a new Command SUC object
         */
        CommandSUC() = default;
        /**
         * @brief Destroy the Command SUC object
         */
        ~CommandSUC() = default;

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
#endif /* !COMMANDSUC_HPP_ */
