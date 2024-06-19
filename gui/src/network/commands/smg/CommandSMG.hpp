/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSMG
*/

#ifndef COMMANDSMG_HPP_
    #define COMMANDSMG_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandSMG : public ICommand {
    public:
        /**
         * @brief Construct a new Command SMG object
         */
        CommandSMG() = default;
        /**
         * @brief Destroy the Command SMG object
         */
        ~CommandSMG() = default;

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
#endif /* !COMMANDSMG_HPP_ */
