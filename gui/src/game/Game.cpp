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
    InitWindow(1600, 900, "Zappy");
    SetTargetFPS(120);
    _client.handleConnection();
    std::cout << "GUI LOG: Connected to the server" << std::endl;
    _client._socket.get()->send("GRAPHIC\n");
    std::cout << "GUI LOG: Sent GRAPHIC" << std::endl;
    std::vector<std::string> data = _client.readData();
    createWorld(data);
    initTimeUnit(data);
    data.clear();
    _camera = {0};
    _camera.position = {0.0f, 10.0f, 10.0f};
    _camera.target = {0.0f, 0.0f, 0.0f};
    _camera.up = Vector3{0.0f, 1.0f, 0.0f};
    _camera.fovy = 90.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

void Game::runGame()
{
    std::vector<std::string> data;
    network::ProtocolHandler protocolHandler(_commandFactory);
    initializeCallbacks();

    while (!WindowShouldClose()) {
        UpdateCamera(&_camera, CAMERA_FREE);
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode3D(_camera);
        DrawTiles(_world.getTiles());
        DrawGrid(20, 10.0f);
        DrawObjects(_world.getObjects());
        data = _client.readData();
        protocolHandler.handleData(data);
        EndMode3D();
        DrawFPS(10, 10);
        EndDrawing();
        data.clear();
    }
    CloseWindow();
}

void Game::DrawTiles(std::vector<std::vector<Tile>> tiles)
{
    for (auto &tiles : _world.getTiles()) {
        for (auto &tile : tiles) {
            DrawCube({static_cast<float>(tile.getPosition().getX()), 0.0f,
                static_cast<float>(tile.getPosition().getY())}, 1.0f, 1.0f, 1.0f, BLACK);
            DrawCubeWires({static_cast<float>(tile.getPosition().getX()), 0.0f,
                static_cast<float>(tile.getPosition().getY())}, 1.0f, 1.0f, 1.0f, YELLOW);
        }
    }
}

void Game::DrawObjects(std::list<IObject *> objects)
{
    for (auto &object : _world.getObjects()) {
        if (object->getType() == 0) {
            DrawSphere({static_cast<float>(object->getPosition().getX()), 1.0f,
                static_cast<float>(object->getPosition().getY())}, 0.3f, RED);
        } else {
            DrawSphere({static_cast<float>(object->getPosition().getX()), 1.0f,
                static_cast<float>(object->getPosition().getY())}, 0.3f, BLUE);
        }
    }
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

void Game::initializeCallbacks()
{
    _commandFactory.setCallback("bct", [this](std::istringstream &iss) {
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

    _commandFactory.setCallback("tna", [this](std::istringstream &iss) {
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

    _commandFactory.setCallback("pnw", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        Trantorian player(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]),
            std::stoi(tokens[4]), std::stoi(tokens[5]), tokens[7]);
        for (auto &team : Teams::getTeamsList()) {
            if (team.getName() == tokens[7]) {
                team.addTrantorian(player);
                std::cout << "GUI LOG: Player " << player.getId() << " added to team "
                    << team.getName() << std::endl;
            }
        }
    });

    _commandFactory.setCallback("ppo", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    trantorian.setPosition(std::stoi(tokens[2]), std::stoi(tokens[3]));
                    trantorian.setOrientation(std::stoi(tokens[4]));
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " position updated" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("plv", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    trantorian.setLevel(std::stoi(tokens[2]));
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " level updated" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("msz", [this](std::istringstream &iss) {
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

    _commandFactory.setCallback("pin", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    trantorian.setInventory(tokens);
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " level updated" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pex", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    // HANDLE EXPULSION
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " has been expulsed" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pbc", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    // HANDLE BROADCAST
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " has broadcasted: " << tokens[2] << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pfk", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    // HANDLE ACTION LAYING EGG
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " is laying an egg" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pfk", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    // HANDLE ACTION LAYING EGG
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " is laying an egg" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pie", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);
        // HANDLE INCANTATION END
    });

    _commandFactory.setCallback("pic", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);
        // HANDLE INCANTATION START
    });

    _commandFactory.setCallback("sst", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        _timeUnit = std::stoi(tokens[1]);
        std::cout << "GUI LOG: New time unit set (" << _timeUnit << ")" << std::endl;
    });
}
