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
        CommandMapSize();
        ~CommandMapSize();

        void execute(const std::vector<std::string> &args,
            ASocket &socket) override;

    protected:
    private:
    };
} // namespace network //
#endif /* !COMMANDMAPSIZE_HPP_ */
