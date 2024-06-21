/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPNW
*/

#ifndef COMMANDPNW_HPP_
    #define COMMANDPNW_HPP_

    #include "network/commands/interface/ICommand.hpp"

namespace network {
    class CommandPNW : public ICommand {
    public:
        /**
         * @brief Construct a new Command PNW object
         */
        CommandPNW() = default;
        /**
         * @brief Destroy the Command PNW object
         */
        ~CommandPNW() = default;

        /**
         * @brief Execute the command
         * @param std::istringstream &iss
         */
        void execute(std::istringstream &iss) final;
        /**
         * @brief Clone the command
         * @return std::unique_ptr<ICommand>
         */
        std::unique_ptr<ICommand> clone() const final;
    };
} // namespace network //
#endif /* !COMMANDPNW_HPP_ */
