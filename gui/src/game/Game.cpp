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
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        int x = std::stoi(tokens[1]);
        int y = std::stoi(tokens[2]);

        for (auto &tiles : _world.getTiles()) {
            for (auto &tile : tiles) {
                if (tile.getPosition().getX() == x && tile.getPosition().getY() == y) {
                    tile.updateTileContent(tokens);
                    std::cout << "GUI LOG: Content of the Tile (" << x << ", "
                        << y << ") updated" << std::endl;
                }
            }
        }
    });

    commandFactory.setCallback("tna", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        Teams team(tokens[1]);
        _teams.addTeamToTeamsList(team);
        std::list<Teams> teams = Teams::getTeamsList();
        std::cout << "GUI LOG: There is " << teams.size() << " teams" << std::endl;
    });

    commandFactory.setCallback("pnw", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        Trantorian player(std::stoi(tokens[1]), std::stoi(tokens[2]), std::stoi(tokens[3]),
            std::stoi(tokens[4]), std::stoi(tokens[5]), tokens[7]);
        for (auto &team : Teams::getTeamsList()) {
            if (team.getName() == tokens[7]) {
                team.addTrantorian(player);
                std::cout << "GUI LOG: Player " << player.getId() << " added to team "
                    << team.getName() << std::endl;
            }
        }
    });

    commandFactory.setCallback("ppo", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == std::stoi(tokens[1])) {
                    trantorian.setPosition(std::stoi(tokens[2]), std::stoi(tokens[3]));
                    trantorian.setOrientation(std::stoi(tokens[4]));
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " position updated" << std::endl;
                }
            }
        }
    });

    commandFactory.setCallback("plv", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == std::stoi(tokens[1])) {
                    trantorian.setLevel(std::stoi(tokens[2]));
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " level updated" << std::endl;
                }
            }
        }
    });

    commandFactory.setCallback("msz", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        _world = World(std::stoi(tokens[1]), std::stoi(tokens[2]));
        std::cout << "GUI LOG: World size updated (" <<
            _world.getHeight() << ", " << _world.getWidth() << ")" << std::endl;
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        data = _client.readData();
        protocolHandler.handleData(data);
        DrawText("Congrats! You created your first window!", 420, 360, 20, BLACK);
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
        for (int y = 0; y < _world.getHeight(); y++) {
            for (int x = 0; x < _world.getWidth(); x++) {
                _world.addTile(Tile(Position(x, y)));
            }
        }
    }
    std::cout << "GUI LOG: World created (" << _world.getHeight() << ", "
        << _world.getWidth() << ")" << std::endl;
    std::cout << "GUI LOG: Tiles created (" << (_world.getTiles().size()
        * _world.getTiles().size()) << ")" << std::endl;
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
