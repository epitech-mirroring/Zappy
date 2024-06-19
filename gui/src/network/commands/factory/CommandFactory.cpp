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
    _commands["pex"] = std::make_unique<CommandPEX>();
    _commands["pfk"] = std::make_unique<CommandPFK>();
    _commands["pie"] = std::make_unique<CommandPIE>();
    _commands["sst"] = std::make_unique<CommandSST>();
    _commands["sgt"] = std::make_unique<CommandSGT>();
    _commands["pdi"] = std::make_unique<CommandPDI>();
    _commands["pbc"] = std::make_unique<CommandPBC>();
    _commands["pic"] = std::make_unique<CommandPIC>();
    _commands["pdr"] = std::make_unique<CommandPDR>();
    _commands["pgt"] = std::make_unique<CommandPGT>();
    _commands["enw"] = std::make_unique<CommandENW>();
    _commands["ebo"] = std::make_unique<CommandEBO>();
    _commands["edi"] = std::make_unique<CommandEDI>();
    _commands["seg"] = std::make_unique<CommandSEG>();
    // SMG message from the server
    // SUC unkown command
    // SBP command parameter
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
