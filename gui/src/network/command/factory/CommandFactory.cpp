/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#include "CommandFactory.hpp"

using namespace network;

CommandFactory::CommandFactory()
    // Add more commands here
{
    _commands["msz"] = std::make_unique<CommandMapSize>();
    _commands["GRAPHIC"] = std::make_unique<CommandMapSize>();
}

std::unique_ptr<ICommand> CommandFactory::getCommand(const std::string &commandName)
{
    auto it = _commands.find(commandName);
    if (it != _commands.end()) {
        return std::move(it->second);
    }
    return nullptr;
}

