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

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        data = _client.readData();
        //handle the data following the protocol. (start by handling bct, then tna)
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
            _world = std::make_shared<World>(std::stoi(tokens[1]), std::stoi(tokens[2]));
            break;
        }
    }
    std::cout << "GUI LOG: World created (" << _world.get()->getHeight() << ", "
        << _world.get()->getWidth() << ")" << std::endl;
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

// void Game::createTeams(std::vector<std::string> data)
// {
//     if (!_teams) {
//         _teams = std::make_shared<Teams>();
//     }

//     for (auto &line : data) {
//         std::istringstream iss(line);
//         std::vector<std::string> tokens;
//         std::string token;
//         while (std::getline(iss, token, ' ')) {
//             tokens.push_back(token);
//         }
//         if (tokens[0] == "tna") {
//             std::string teamName = tokens[1];
//             if (_teams->getTeamByName(teamName) == nullptr) {
//                 Teams newTeam(teamName);
//                 _teams->addTeamToTeamsList(newTeam);
//                 std::cout << "GUI LOG: Team created (" << teamName << ")" << std::endl;
//             }
//         }
//     }
// }
