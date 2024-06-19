/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandSBP
*/

#ifndef COMMANDSBP_HPP_
    #define COMMANDSBP_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandSBP : public ICommand {
    public:
        /**
         * @brief Construct a new Command SBP object
         */
        CommandSBP() = default;
        /**
         * @brief Destroy the Command SBP object
         */
        ~CommandSBP() = default;

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
#endif /* !COMMANDSBP_HPP_ */
