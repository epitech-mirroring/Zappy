/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPLV
*/

#ifndef COMMANDPLV_HPP_
    #define COMMANDPLV_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPLV : public ICommand {
    public:
        /**
         * @brief Construct a new Command PLV object
         */
        CommandPLV() = default;
        /**
         * @brief Destroy the Command PLV object
         */
        ~CommandPLV() = default;

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
#endif /* !COMMANDPLV_HPP_ */
