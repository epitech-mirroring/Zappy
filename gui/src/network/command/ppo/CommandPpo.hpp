/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPpo
*/

#ifndef COMMANDPPO_HPP_
    #define COMMANDPPO_HPP_

    #include "network/command/interface/ITeamsCommand.hpp"

namespace network {
class CommandPpo : public ITeamsCommand {
    private:
        GUI::Teams *_teams;
    public:
        CommandPpo() = default;
        ~CommandPpo() = default;

        void execute(std::unique_ptr<ASocket>& socket,
            const std::string& data);

        [[nodiscard]] std::unique_ptr<ICommand> clone() const;

        void linkTeams(GUI::Teams *teams);
};
} // namespace network //
#endif /* !COMMANDPPO_HPP_ */
