/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ITeamsCommand
*/

#ifndef ITEAMSCOMMAND_HPP_
    #define ITEAMSCOMMAND_HPP_

    #include "network/command/interface/ICommand.hpp"
    #include "trantorians/Teams.hpp"
    #include <functional>
    #include <sstream>
    #include <memory>
    #include <vector>
    #include <string>
    #include "network/socket/ASocket.hpp"

namespace network {
    class ITeamsCommand : public ICommand {
    public:
        ITeamsCommand() noexcept = default;
        ~ITeamsCommand() noexcept = default;

        virtual void linkTeams(GUI::Teams *teams) = 0;
    };
} // namespace network //
#endif /* !ITEAMSCOMMAND_HPP_ */
