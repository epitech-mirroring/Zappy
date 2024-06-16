/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#include "CommandFactory.hpp"

using namespace network;

CommandFactory::CommandFactory()
{
    _commands["bct"] = std::make_unique<CommandBCT>();
    _commands["tna"] = std::make_unique<CommandTNA>();
    _commands["pnw"] = std::make_unique<CommandPNW>();
    _commands["ppo"] = std::make_unique<CommandPPO>();
    _commands["plv"] = std::make_unique<CommandPLV>();
    _commands["msz"] = std::make_unique<CommandMSZ>();
    _commands["pin"] = std::make_unique<CommandPIN>();
}

std::unique_ptr<ICommand> CommandFactory::createCommand(const std::string&
    commandName)
{
    auto it = _commands.find(commandName);
    if (it != _commands.end()) {
        auto command = it->second->clone();
        auto cbIt = _callbacks.find(commandName);
        if (cbIt != _callbacks.end()) {
            command->setCallback(cbIt->second);
        }
        return command;
    }
    return nullptr;
}

void CommandFactory::setCallback(const std::string& commandName,
    ICommand::Callback callback)
{
    _callbacks[commandName] = std::move(callback);
}

void CommandFactory::execute(std::istringstream& iss)
{
    (void)iss;
    return;
}

std::unique_ptr<ICommand> CommandFactory::clone() const
{
    return nullptr;
}
