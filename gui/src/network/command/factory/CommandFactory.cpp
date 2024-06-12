/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** CommandFactory
*/

#include "CommandFactory.hpp"

using namespace network;

CommandFactory::CommandFactory(GUI::World &world, GUI::Teams &teams)
{
    _commands["msz"] = std::make_unique<CommandMapSize>();
    _responseCommands["msz"] = std::make_unique<CommandMapSizeResponse>();

    _commands["bct"] = std::make_unique<CommandBct>();
    _responseCommands["bct"] = std::make_unique<CommandBctReceive>();

    _commands["tna"] = std::make_unique<CommandTna>();
    _responseCommands["tna"] = std::make_unique<CommandTnaReceive>();

    _commands["ppo"] = std::make_unique<CommandPpo>();
    _responseCommands["ppo"] = std::make_unique<CommandPpoReceive>();

    for (auto &command : _commands) {
        if (auto worldCommand = dynamic_cast<IWorldCommand *>(command.second.get()))
            worldCommand->linkWorld(&world);
        if (auto teamsCommand = dynamic_cast<ITeamsCommand *>(command.second.get()))
            teamsCommand->linkTeams(&teams);
    }
    for (auto &command : _responseCommands) {
        if (auto worldCommand = dynamic_cast<IWorldCommand *>(command.second.get()))
            worldCommand->linkWorld(&world);
        if (auto teamsCommand = dynamic_cast<ITeamsCommand *>(command.second.get()))
            teamsCommand->linkTeams(&teams);
    }
}

std::unique_ptr<ICommand> CommandFactory::getCommand(const
    std::string &commandName)
{
    auto it = _commands.find(commandName);
    if (it != _commands.end()) {
        return it->second->clone();
    }
    return nullptr;
}

std::unique_ptr<ICommand> CommandFactory::getResponseCommand(const
    std::string &responseName)
{
    auto it = _responseCommands.find(responseName);
    if (it != _responseCommands.end()) {
        return it->second->clone();
    }
    return nullptr;
}
