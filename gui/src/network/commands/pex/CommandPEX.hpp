/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPEX
*/

#ifndef COMMANDPEX_HPP_
    #define COMMANDPEX_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPEX : public ICommand {
    public:
        /**
         * @brief Construct a new Command PLV object
         */
        CommandPEX() = default;
        /**
         * @brief Destroy the Command PLV object
         */
        ~CommandPEX() = default;

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
}   // namespace network //
#endif /* !COMMANDPEX_HPP_ */
