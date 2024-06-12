/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandTnaReceive
*/

#ifndef COMMANDTNARECEIVE_HPP_
    #define COMMANDTNARECEIVE_HPP_

    #include "network/command/interface/ITeamsCommand.hpp"

namespace network {
    class CommandTnaReceive : public ITeamsCommand {
    private:
        GUI::Teams *_teams;
    public:
        CommandTnaReceive();
        ~CommandTnaReceive() = default;

        void execute(std::unique_ptr<ASocket>& socket,
            const std::string& data) override;

        [[nodiscard]] std::unique_ptr<ICommand> clone() const override;

        void linkTeams(GUI::Teams *teams) override;
    };
} // namespace network //
#endif /* !COMMANDTNARECEIVE_HPP_ */
