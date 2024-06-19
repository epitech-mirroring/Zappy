/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSEG
*/

#ifndef COMMANDSEG_HPP_
    #define COMMANDSEG_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandSEG : public ICommand {
    public:
        /**
         * @brief Construct a new Command SEG object
         */
        CommandSEG() = default;
        /**
         * @brief Destroy the Command SEG object
         */
        ~CommandSEG() = default;

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
#endif /* !COMMANDSEG_HPP_ */
