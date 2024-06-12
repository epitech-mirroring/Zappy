/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandExpulsion
*/

#ifndef COMMANDEXPULSION_HPP_
    #define COMMANDEXPULSION_HPP_

    #include "network/command/interface/IWorldCommand.hpp"
    #include "trantorians/Trantorian.hpp"

namespace network {
    class CommandExpulsion : public IWorldCommand, GUI::Trantorian {
        private:
            GUI::World *_world;
        public:
            /**
             * @brief Construct a new Command Expulsion object
             */
            CommandExpulsion();
            /**
             * @brief Destroy the Command Expulsion object
             */
            ~CommandExpulsion() = default;

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
} // namespace network

#endif // COMMANDEXPULSION_HPP_
