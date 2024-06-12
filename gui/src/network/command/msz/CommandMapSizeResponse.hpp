/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSizeResponse
*/

#ifndef COMMANDMAPSIZERESPONSE_HPP_
    #define COMMANDMAPSIZERESPONSE_HPP_

    #include "network/command/interface/IWorldCommand.hpp"

namespace network {
    class CommandMapSizeResponse : public IWorldCommand {
    private:
        GUI::World *_world;
    public:
        /**
         * @brief Construct a new Command Map Size Response object
         */
        CommandMapSizeResponse();
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
        [[nodiscard]] std::unique_ptr<ICommand> clone() const override;

        void linkWorld(GUI::World *world) override;
    };
} // namespace network //
#endif /* !COMMANDMAPSIZERESPONSE_HPP_ */
