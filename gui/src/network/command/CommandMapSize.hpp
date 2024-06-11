/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSize
*/

#ifndef COMMANDMAPSIZE_HPP_
    #define COMMANDMAPSIZE_HPP_

    #include "network/command/interface/ICommand.hpp"

namespace network {
    class CommandMapSize : public ICommand {
    public:
        CommandMapSize() = default;
        ~CommandMapSize() = default;

        void execute(std::unique_ptr<ASocket>& socket) override;
    };
} // namespace network //
#endif /* !COMMANDMAPSIZE_HPP_ */
