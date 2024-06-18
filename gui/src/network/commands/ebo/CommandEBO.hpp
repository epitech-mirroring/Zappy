/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandEBO
*/

#ifndef COMMANDEBO_HPP_
    #define COMMANDEBO_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandEBO : public ICommand {
    public:
        /**
         * @brief Construct a new Command EBO object
         */
        CommandEBO() = default;
        /**
         * @brief Destroy the Command EBO object
         */
        ~CommandEBO() = default;

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
#endif /* !COMMANDEBO_HPP_ */
