/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandMapSize
*/

#ifndef COMMANDMAPSIZE_HPP_
    #define COMMANDMAPSIZE_HPP_

    #include "network/command/interface/IWorldCommand.hpp"

namespace network {
    class CommandMapSize : public IWorldCommand {
    private:
        GUI::World *_world;
    public:
        /**
         * @brief Construct a new Command Map Size object
         */
        CommandMapSize() = default;
        /**
         * @brief Destroy the Command Map Size object
         */
        ~CommandMapSize() = default;

        /**
         * @brief Execute the command
         * @param socket (socket of the client)
         * @param data (data of the command)
         */
        void execute(std::unique_ptr<ASocket>& socket,
            const std::string& data) override;
        /**
         * @brief Clone the command
         */
        [[nodiscard]] std::unique_ptr<ICommand> clone() const override;

        void linkWorld(GUI::World *world) override;
    };
} // namespace network //
#endif /* !COMMANDMAPSIZE_HPP_ */