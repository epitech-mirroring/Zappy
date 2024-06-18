/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandENW
*/

#ifndef COMMANDENW_HPP_
    #define COMMANDENW_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandENW : public ICommand {
    public:
        /**
         * @brief Construct a new Command ENW object
         */
        CommandENW() = default;
        /**
         * @brief Destroy the Command ENW object
         */
        ~CommandENW() = default;

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
#endif /* !COMMANDENW_HPP_ */
