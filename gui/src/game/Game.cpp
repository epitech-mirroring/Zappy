/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Game
*/

#include "Game.hpp"

using namespace GUI;

Game::Game(std::string hostname, unsigned int port)
    : _client(hostname, port)
{
}

Game::~Game()
{
}

void Game::initGame()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "Zappy");
    SetTargetFPS(60);
    _client.handleConnection();
    std::cout << "GUI LOG: Connected to the server" << std::endl;
    _client._socket.get()->send("GRAPHIC\n");
    std::cout << "GUI LOG: Sent GRAPHIC" << std::endl;
    std::vector<std::string> data = _client.readData();
    createWorld(data);
    initTimeUnit(data);
    data.clear();
}

void Game::runGame()
{
    std::vector<std::string> data;
    network::CommandFactory commandFactory;
    network::ProtocolHandler protocolHandler(commandFactory);

    commandFactory.setCallback("bct", [this](std::istringstream &iss) {
        std::cout << "GUI LOG: Received BCT command" << std::endl;
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        data = _client.readData();
        protocolHandler.handleData(data);
        DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);
        EndDrawing();
        data.clear();
    }
    CloseWindow();
}

void Game::createWorld(std::vector<std::string> data)
{
    for (auto &line : data) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        if (tokens[0] == "msz") {
            _world = World(std::stoi(tokens[1]), std::stoi(tokens[2]));
            break;
        }
    }
    std::cout << "GUI LOG: World created (" << _world.getHeight() << ", "
        << _world.getWidth() << ")" << std::endl;
}

void Game::initTimeUnit(std::vector<std::string> data)
{
    for (auto &line : data) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        if (tokens[0] == "sgt") {
            _timeUnit = std::stoi(tokens[1]);
            break;
        }
    }
    std::cout << "GUI LOG: Time unit set (" << _timeUnit << ")" << std::endl;
}
