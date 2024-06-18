/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPDI
*/

#ifndef COMMANDPDI_HPP_
    #define COMMANDPDI_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPDI : public ICommand {
    public:
        /**
         * @brief Construct a new Command PDI object
         */
        CommandPDI() = default;
        /**
         * @brief Destroy the Command PDI object
         */
        ~CommandPDI() = default;

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
#endif /* !COMMANDPDI_HPP_ */
