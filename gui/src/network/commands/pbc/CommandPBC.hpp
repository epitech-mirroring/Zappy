/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPBC
*/

#ifndef COMMANDPBC_HPP_
    #define COMMANDPBC_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPBC : public ICommand {
    public:
        /**
         * @brief Construct a new Command PBC object
         */
        CommandPBC() = default;
        /**
         * @brief Destroy the Command PBC object
         */
        ~CommandPBC() = default;

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
#endif /* !COMMANDPBC_HPP_ */
