/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPDR
*/

#ifndef COMMANDPDR_HPP_
    #define COMMANDPDR_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPDR : public ICommand {
    public:
        /**
         * @brief Construct a new Command PDR object
         */
        CommandPDR() = default;
        /**
         * @brief Destroy the Command PDR object
         */
        ~CommandPDR() = default;

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
#endif /* !COMMANDPDR_HPP_ */
