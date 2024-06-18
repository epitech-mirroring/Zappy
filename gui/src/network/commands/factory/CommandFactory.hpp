/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#ifndef COMMANDFACTORY_HPP_
    #define COMMANDFACTORY_HPP_

    #include "network/commands/bct/CommandBCT.hpp"
    #include "network/commands/tna/CommandTNA.hpp"
    #include "network/commands/pnw/CommandPNW.hpp"
    #include "network/commands/ppo/CommandPPO.hpp"
    #include "network/commands/plv/CommandPLV.hpp"
    #include "network/commands/msz/CommandMSZ.hpp"
    #include "network/commands/pin/CommandPIN.hpp"
    #include "network/commands/pex/CommandPEX.hpp"
    #include "network/commands/pbc/CommandPBC.hpp"
    #include "network/commands/pfk/CommandPFK.hpp"
    #include "network/commands/pie/CommandPIE.hpp"
    #include "network/commands/pic/CommandPIC.hpp"
    #include "network/commands/sst/CommandSST.hpp"
    #include "network/commands/sgt/CommandSGT.hpp"
    #include "network/commands/pdi/CommandPDI.hpp"
    #include "network/commands/pdr/CommandPDR.hpp"
    #include "network/commands/pgt/CommandPGT.hpp"
    #include "network/commands/enw/CommandENW.hpp"

    #include "network/commands/interface/ICommand.hpp"
    #include <unordered_map>
    #include <string>
    #include <memory>

namespace network {
    class CommandFactory : public ICommand {
    public:
        /**
         * @brief Construct a new Command Factory object
         */
        CommandFactory();
        /**
         * @brief Destroy the Command Factory object
         */
        ~CommandFactory() = default;

        /**
         * @brief Execute the command
         * @param std::string commandName, name of the command to create
         * @return std::unique_ptr<ICommand> the created command
         */
        std::unique_ptr<ICommand> createCommand(const std::string& commandName);

        /**
         * @brief Execute the command
         * @param std::string &commandName, name of the command to create
         * @param Callback callback, the callback to attach to the command
         */
        void setCallback(const std::string& commandName,
            ICommand::Callback callback);

        /**
         * @brief Execute the command
         * @param std::istringstream &iss, the command to execute
         */
        void execute(std::istringstream& iss) override;

        /**
         * @brief Clone the command
         */
        std::unique_ptr<ICommand> clone() const override;

    private:
        std::unordered_map<std::string,
            std::unique_ptr<ICommand>> _commands;   // Map of commands
        std::unordered_map<std::string,
            ICommand::Callback> _callbacks;         // Map of callbacks
    };
} // namespace network //
#endif /* !COMMANDFACTORY_HPP_ */
