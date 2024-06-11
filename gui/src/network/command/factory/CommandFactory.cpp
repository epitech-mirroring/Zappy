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
    _commands["msz"] = std::make_unique<CommandMapSize>();
    _responseCommands["msz"] = std::make_unique<CommandMapSizeResponse>();
}

std::unique_ptr<ICommand> CommandFactory::getCommand(const std::string &commandName)
{
    auto it = _commands.find(commandName);
    if (it != _commands.end()) {
        return it->second->clone();
    }
    return nullptr;
}

std::unique_ptr<ICommand> CommandFactory::getResponseCommand(const std::string &responseName)
{
    auto it = _responseCommands.find(responseName);
    if (it != _responseCommands.end()) {
        return it->second->clone();
    }
    return nullptr;
}
