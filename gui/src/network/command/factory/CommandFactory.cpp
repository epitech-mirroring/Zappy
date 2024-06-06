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
}
