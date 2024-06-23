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
    , _display(_world, _teams)
{
}

void Game::initGame()
{
    _client.handleConnection();
    std::cout << "GUI LOG: Connected to the server" << std::endl;

    _client._socket.get()->send("GRAPHIC\n");
    std::cout << "GUI LOG: Sent GRAPHIC" << std::endl;

    std::vector<std::string> data = _client.readData();
    createWorld(data);

    data.clear();
}

void Game::runGame()
{
    Events events;

    std::vector<std::string> data;
    network::ProtocolHandler protocolHandler(_commandFactory);

    initializeCallbacks();

    while (_display.windowShouldClose() == false) {
        ensureGameInit();
        _display.setTimeUnit(_timeUnit);
        handleNewTimeUnit();
        _display.displayElements();
        data = _client.readData();
        protocolHandler.handleData(data);
        data.clear();
        ensureGameInformation();
    }
    _display.closeWindow();
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
    std::cout << "GUI LOG: Clouds created (" << _display.getClouds().size() << ")" << std::endl;
}

void Game::handleNewTimeUnit()
{
    std::string newTimeUnitStr = _display.getNewTimeUnit();
    try {
        if (newTimeUnitStr != "" && (std::stoi(newTimeUnitStr) != _timeUnit)) {
            std::string request = "sst " + newTimeUnitStr + "\n";
            _client._socket.get()->send(request);
            _timeUnit = std::stoi(newTimeUnitStr);
            std::cout << "GUI LOG: Sent SGT: " << newTimeUnitStr << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "INVALID TIME UNIT" << std::endl;
        newTimeUnitStr.clear();
        _display.setNewTimeUnit(newTimeUnitStr);
    } catch (const std::out_of_range& e) {
        std::cerr << "INVALID TIME UNIT" << std::endl;
        newTimeUnitStr.clear();
        _display.setNewTimeUnit(newTimeUnitStr);
    }
}

void Game::ensureGameInit()
{
    if (_world.getHeight() == 0 && _world.getWidth() == 0) {
        _client._socket.get()->send("msz\n");
    }
    if (_timeUnit == 0) {
        _client._socket.get()->send("sgt\n");
    }
    if (Teams::getTeamsList().size() == 0) {
        _client._socket.get()->send("tna\n");
    }
}

void Game::ensureGameInformation()
{
    _client._socket.get()->send("mct\n");
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

        std::vector<std::string> tileContent;
        for (size_t i = 3; i < tokens.size(); i++) {
            tileContent.push_back(tokens[i]);
        }

        for (auto &tiles : _world.getTiles()) {
            for (auto &tile : tiles) {
                if (tile.getPosition().getX() == x && tile.getPosition().getY() == y) {
                    tile.updateTileContent(tileContent);
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
        std::string log = "GUI LOG: Team " + tokens[1] + " added";
        _display.addLog(log);
        std::cout << "GUI LOG: There is " << teams.size() << " teams" << std::endl;
    });

    _commandFactory.setCallback("pnw", [this](std::istringstream &iss) {
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' ')) {
            tokens.push_back(token);
        }

        int orientation = std::stoi(tokens[4]);
        float orientationFloat = static_cast<float>(orientation);
        Trantorian player(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]),
                        orientationFloat, std::stoi(tokens[5]));

        for (auto &team : Teams::getTeamsList()) {
            if (team.getName() == tokens[6]) {
                team.addTrantorian(player);
                std::string log = "GUI LOG: Player " + player.getId() +
                    " added to " + team.getName();
                _display.addLog(log);
                std::cout << "GUI LOG: Player " << player.getId() <<
                    " added to team " << team.getName() << std::endl;
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

        int orientation = std::stoi(tokens[4]);
        float orientationFloat = static_cast<float>(orientation);
        for (auto& team : Teams::getTeamsList()) {
            Trantorian* trantorian = team.getTrantorianByIdMod(tokens[1]);
            if (trantorian != nullptr) {
                trantorian->setPosition(std::stoi(tokens[2]), std::stoi(tokens[3]));
                trantorian->setOrientation(orientationFloat);
                std::cout << "GUI LOG: Player " << trantorian->getId()
                    << " position updated to (" << trantorian->getPosition().getX() << ", "
                    << trantorian->getPosition().getY() << ")" << std::endl;
                break;
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
                    std::string log = "GUI LOG: Player " + trantorian.getId() +
                        " level updated";
                    _display.addLog(log);
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
        std::string log = "GUI LOG: World created (" + tokens[1] + ", " + tokens[2] + ")";
        _display.addLog(log);
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

        for (auto& team : Teams::getTeamsList()) {
            Trantorian* trantorian = team.getTrantorianByIdMod(tokens[1]);
            if (trantorian != nullptr) {
                trantorian->setInventory(tokens);
                std::cout << "GUI LOG: Player " << trantorian->getId()
                    << " inventory updated" << std::endl;
                break;
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
                    std::string log = "GUI LOG: Player " + trantorian.getId() + " expulsed";
                    _display.addLog(log);
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
                    std::string log = "GUI LOG: Player " + trantorian.getId() +
                        " has broadcasted: \n" + tokens[2];
                    _display.addLog(log);
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
                    std::string log = "GUI LOG: Player " + trantorian.getId() +
                        "laying an egg";
                    _display.addLog(log);
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
        std::string log = "GUI LOG: Incantation ended";
        _display.addLog(log);
        std::cout << "GUI LOG: Incantation ended" << std::endl;
    });

    _commandFactory.setCallback("pic", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);
        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    std::string log = "GUI LOG: Player " + trantorian.getId() + " started incantation";
                    _display.addLog(log);
                    std::cout << "GUI LOG: Incantation started by player " << trantorian.getId() << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("sst", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        _timeUnit = std::stoi(tokens[1]);
        std::string log = "GUI LOG: New frequency set (" + std::to_string(_timeUnit) + ")";
        _display.addLog(log);
        std::cout << "GUI LOG: New time unit set (" << _timeUnit << ")" << std::endl;
    });

    _commandFactory.setCallback("sgt", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        _timeUnit = std::stoi(tokens[1]);
        std::string log = "GUI LOG: frequency received (" + std::to_string(_timeUnit) + ")";
        _display.addLog(log);
        std::cout << "GUI LOG: Time unit requested (" << _timeUnit << ")" << std::endl;
    });

    _commandFactory.setCallback("pdi", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    trantorian.setIsAlive(false);
                    std::string log = "GUI LOG: Player " + trantorian.getId() + " died";
                    _display.addLog(log);
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " died" << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pdr", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    for (auto &inventory : trantorian.getInventory()) {
                        // HANDLE RESSOURCE DROPPING
                    }
                    std::string log = "GUI LOG: Player " + trantorian.getId() +
                        " dropped: " + tokens[2];
                    _display.addLog(log);
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " has dropped: " << tokens[2] << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("pgt", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == tokens[1]) {
                    for (auto &inventory : trantorian.getInventory()) {
                        // HANDLE RESSOURCE COLLECTING
                    }
                    std::string log = "GUI LOG: Player " + trantorian.getId() +
                        " collected: " + tokens[2];
                    _display.addLog(log);
                    std::cout << "GUI LOG: Player " << trantorian.getId()
                        << " has collected: " << tokens[2] << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("enw", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        int eggNb = std::stoi(tokens[1]);
        std::string trantorianId = tokens[2];
        int x = std::stoi(tokens[3]);
        int y = std::stoi(tokens[4]);

        for (auto &team : Teams::getTeamsList()) {
            for (auto &trantorian : team.getTrantorianList()) {
                if (trantorian.getId() == trantorianId) {
                    Position pos;
                    pos.setX(x);
                    pos.setY(y);
                    Egg egg(team.getName(), trantorianId, pos);
                    team.addEggToList(egg);
                    std::string log = "GUI LOG: Egg " + std::to_string(eggNb) +
                        " layed by player " + trantorianId;
                    _display.addLog(log);
                    std::cout << "GUI LOG: Egg " << eggNb
                        << " has been layed by player " << trantorianId << std::endl;
                }
            }
        }
    });

    _commandFactory.setCallback("ebo", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        // HANDLE PLAYER CONNECTION FOR AN EGG
        std::string log = "GUI LOG: Player connection for " + tokens[1] + " Egg";
        _display.addLog(log);
        std::cout << "GUI LOG: Player connection for " << token[1] << " Egg" << std::endl;
    });

    _commandFactory.setCallback("edi", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        // HANDLE DEATH FOR AN EGG
        std::string log = "GUI LOG: Death of " + tokens[1] + " Egg";
        _display.addLog(log);
        std::cout << "GUI LOG: Death of " << token[1] << " Egg" << std::endl;
    });

    _commandFactory.setCallback("seg", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        // HANDLE END OF GAME
        std::string log = "GUI LOG: Team " + tokens[1] + " end the game";
        _display.addLog(log);
        std::cout << "GUI LOG: Team " << token[1] << " end the game" << std::endl;
    });

    _commandFactory.setCallback("smg", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        // HANDLE MESSAGE FROM THE SERVER
        std::string log = "GUI LOG: Message from the server: " + tokens[1];
        _display.addLog(log);
        std::cout << "GUI LOG: Message from the server: " << token[1] << std::endl;
    });

    _commandFactory.setCallback("suc", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        // HANDLE UNKNOWN COMMAND
        std::string log = "GUI LOG: Unkown command";
        _display.addLog(log);
        std::cout << "GUI LOG: Unkown command" << std::endl;
    });

    _commandFactory.setCallback("sbp", [this](std::istringstream &iss){
        std::string data = iss.str();
        std::istringstream iss2(data);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(iss2, token, ' '))
            tokens.push_back(token);

        // HANDLE COMMAND PARAMETER
        std::string log = "GUI LOG: Command parameter requested";
        _display.addLog(log);
        std::cout << "GUI LOG: Command parameter requested" << std::endl;
    });
}
