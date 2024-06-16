/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSST
*/

#ifndef COMMANDSST_HPP_
    #define COMMANDSST_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandSST : public ICommand {
    public:
        /**
         * @brief Construct a new CommandSST object
         */
        CommandSST() = default;
        /**
         * @brief Destroy the CommandSST object
         */
        ~CommandSST() = default;

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
}
#endif /* !COMMANDSST_HPP_ */
