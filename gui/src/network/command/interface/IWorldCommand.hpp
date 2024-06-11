/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ICommand
*/

#ifndef IWORLDCOMMAND_HPP_
    #define IWORLDCOMMAND_HPP_

    #include <functional>
    #include <sstream>
    #include <memory>
    #include <vector>
    #include <string>
    #include "network/socket/ASocket.hpp"
    #include "network/command/interface/ICommand.hpp"
    #include "world/World.hpp"

namespace network {
    class IWorldCommand: public ICommand {
    public:
        IWorldCommand() noexcept = default;
        virtual ~IWorldCommand() noexcept = default;

        virtual void linkWorld(GUI::World *world) = 0;
    };
} // namespace network //
#endif /* !IWORLDCOMMAND_HPP_ */
