/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ICommand
*/

#ifndef ICOMMAND_HPP_
    #define ICOMMAND_HPP_

    #include <vector>
    #include <string>
    #include "network/socket/ASocket.hpp"

namespace network {
    class ICommand {
    public:
        ICommand() noexcept = default;
        virtual ~ICommand() noexcept = default;

        virtual void execute(const std::vector<std::string> &args,
            ASocket &socket) = 0;

    protected:
    private:
    };
} // namespace network //
#endif /* !ICOMMAND_HPP_ */
