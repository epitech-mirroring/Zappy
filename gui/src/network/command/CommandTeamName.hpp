/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTeamName
*/

#ifndef COMMANDTEAMNAME_HPP_
    #define COMMANDTEAMNAME_HPP_

    #include "network/command/interface/ICommand.hpp"

namespace network {
class CommandTeamName : public ICommand {
    public:
        CommandTeamName() = default;
        ~CommandTeamName() = default;

        void execute(ASocket &socket) override;
};
} // namespace network //
#endif /* !COMMANDTEAMNAME_HPP_ */
