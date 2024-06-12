/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandPpoReceive
*/

#ifndef COMMANDPPORECEIVE_HPP_
    #define COMMANDPPORECEIVE_HPP_

    #include "network/command/interface/ITeamsCommand.hpp"

namespace network {
    class CommandPpoReceive : public ITeamsCommand {
    private:
        GUI::Teams *_teams;
    public:
        CommandPpoReceive();
        ~CommandPpoReceive() = default;

        void execute(std::unique_ptr<ASocket>& socket,
            const std::string& data) override;

        [[nodiscard]] std::unique_ptr<ICommand> clone() const override;

        void linkTeams(GUI::Teams *teams) override;
    };
} // namespace network //
#endif /* !COMMANDPPORECEIVE_HPP_ */
