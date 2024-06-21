/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandBCT
*/

#ifndef COMMANDBCT_HPP_
    #define COMMANDBCT_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandBCT : public ICommand {
    public:
        /**
         * @brief Construct a new Command BCT object
         */
        CommandBCT() = default;
        /**
         * @brief Destroy the Command BCT object
         */
        ~CommandBCT() = default;

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
#endif /* !COMMANDBCT_HPP_ */
