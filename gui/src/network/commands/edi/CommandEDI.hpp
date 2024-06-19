/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandEDI
*/

#ifndef COMMANDEDI_HPP_
    #define COMMANDEDI_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandEDI : public ICommand {
    public:
        /**
         * @brief Construct a new Command EDI object
         */
        CommandEDI() = default;
        /**
         * @brief Destroy the Command EDI object
         */
        ~CommandEDI() = default;

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
#endif /* !COMMANDEDI_HPP_ */
