/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSizeResponse
*/

#ifndef COMMANDMAPSIZERESPONSE_HPP_
    #define COMMANDMAPSIZERESPONSE_HPP_

    #include "network/command/interface/ICommand.hpp"

namespace network {
    class CommandMapSizeResponse : public ICommand {
    public:
        /**
         * @brief Construct a new Command Map Size Response object
         */
        CommandMapSizeResponse() = default;
        /**
         * @brief Destroy the Command Map Size Response object
         */
        ~CommandMapSizeResponse() =default;

        /**
         * @brief Execute the command
         */
        void execute(std::unique_ptr<ASocket>& socket,
            const std::string &data) override;
        /**
         * @brief Clone the command
         */
        std::unique_ptr<ICommand> clone() const override;
    };
} // namespace network //
#endif /* !COMMANDMAPSIZERESPONSE_HPP_ */
