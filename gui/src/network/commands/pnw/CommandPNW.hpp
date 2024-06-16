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
        CommandPNW() = default;
        ~CommandPNW() = default;

        void execute(std::istringstream &iss) final;

        std::unique_ptr<ICommand> clone() const final;

    };
} // namespace network //
#endif /* !COMMANDPNW_HPP_ */
