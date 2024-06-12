/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTna
*/

#ifndef COMMANDTNA_HPP_
    #define COMMANDTNA_HPP_

    #include "network/command/interface/ITeamsCommand.hpp"

namespace network {
    class CommandTna : public ITeamsCommand {
    private:
        GUI::Teams *_teams;
    public:
        CommandTna() = default;
        ~CommandTna() = default;

        void execute(std::unique_ptr<ASocket>& socket,
            const std::string& data) override;

        [[nodiscard]] std::unique_ptr<ICommand> clone() const override;

        void linkTeams(GUI::Teams *teams) override;
    };
} // namespace network //
#endif /* !COMMANDTNA_HPP_ */
