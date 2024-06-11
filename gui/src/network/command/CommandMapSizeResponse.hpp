/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** CommandMapSizeResponse
*/

#ifndef COMMANDMAPSIZERESPONSE_HPP_
    #define COMMANDMAPSIZERESPONSE_HPP_

    #include "network/command/interface/ICommand.hpp"

namespace network {
    class CommandMapSizeResponse : public ICommand {
    public:
        CommandMapSizeResponse() = default;
        ~CommandMapSizeResponse() =default;

        void execute(std::unique_ptr<ASocket>& socket,
            const std::string &data) override;
        std::unique_ptr<ICommand> clone() const override;
    protected:
    private:
    };
} // namespace network //
#endif /* !COMMANDMAPSIZERESPONSE_HPP_ */
