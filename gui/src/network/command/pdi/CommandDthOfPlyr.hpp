/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandDthOfPlyr
*/

#ifndef COMMANDDTHOFPLYR_HPP_
    #define COMMANDDTHOFPLYR_HPP_

    #include "network/command/interface/IWorldCommand.hpp"
    #include "trantorians/Trantorian.hpp"

namespace network {
    class CommandDthOfPlyr : public IWorldCommand, GUI::Trantorian {
        private:
            GUI::World *_world;
            GUI::Trantorian *_trantorian;
        public:
            /**
             * @brief Construct a new Command Death Of Player object
             */
            CommandDthOfPlyr();
            /**
             * @brief Destroy the Command Death Of Player object
             */
            ~CommandDthOfPlyr() =default;

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
#endif /* !COMMANDDTHOFPLYR_HPP_ */
