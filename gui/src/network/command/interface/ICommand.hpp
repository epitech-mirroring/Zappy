/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ICommand
*/

#ifndef ICOMMAND_HPP_
    #define ICOMMAND_HPP_

    #include <memory>
    #include <vector>
    #include <string>
    #include "network/socket/ASocket.hpp"

namespace network {
    class ICommand {
    public:
        ICommand() noexcept = default;
        virtual ~ICommand() noexcept = default;

        virtual void execute(std::unique_ptr<ASocket>& socket) = 0;
    };
} // namespace network //
#endif /* !ICOMMAND_HPP_ */
