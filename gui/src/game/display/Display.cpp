/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Display
*/

#include "Display.hpp"

using namespace GUI;

Display::Display(World &world, Teams &teams)
    : _world(world), _teams(teams)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "Zappy");
    SetTargetFPS(120);
    initClouds();
    _camera = {0};
    _camera.position = {0.0f, 10.0f, 10.0f};
    _camera.target = {0.0f, 0.0f, 0.0f};
    _camera.up = Vector3{0.0f, 1.0f, 0.0f};
    _camera.fovy = 90.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

void Display::DrawTiles(std::vector<std::vector<Tile>> tiles)
{
    for (auto &row : _world.getTiles()) {
        for (auto &tile : row) {
            Color color = (_hoveredTile == &tile) ? YELLOW : GREEN;
            DrawCube({static_cast<float>(tile.getPosition().getX()), 0.0f,
                static_cast<float>(tile.getPosition().getY())}, 1.0f, 1.0f, 1.0f, color);
            DrawCubeWires({static_cast<float>(tile.getPosition().getX()), 0.0f,
                static_cast<float>(tile.getPosition().getY())}, 1.0f, 1.0f, 1.0f, WHITE);
        }
    }
}

void Display::initClouds()
{
    std::vector<std::string> clouds = {
        "gui/src/assets/clouds/CloudLarge2.obj",
        "gui/src/assets/clouds/CloudMedium2.obj",
        "gui/src/assets/clouds/CloudSmall2.obj",
        "gui/src/assets/clouds/CloudSmall3.obj"
    };
    for (int i = 0; i < 7; i++) {
        Model model = LoadModel(clouds[rand() % 4].c_str());
        _clouds.push_back(model);
        _cloudPositions.push_back({static_cast<float>(rand() % 30),
            15.0f, static_cast<float>(rand() % 30)});
    }
}

void Display::DrawClouds()
{
    for (size_t i = 0; i < _clouds.size(); i++) {
        DrawModel(_clouds[i], _cloudPositions[i], 1.0f, WHITE);
    }
}

void Display::DrawTrantorians(std::list<Teams> teams)
{
    for (auto &team : teams) {
        for (auto &trantorian : team.getTrantorianList()) {
            Vector3 position = {
                static_cast<float>(trantorian.getPosition().getX()),
                0.5f,
                static_cast<float>(trantorian.getPosition().getY())
            };
            Vector3 rotationAxis = {0.0f, 1.0f, 0.0f};
            Vector3 scale = {1.0f, 1.0f, 1.0f};

            DrawModelEx(trantorian.getModel(), position, rotationAxis, trantorian.getOrientation(), scale, WHITE);

            BoundingBox box = {
                {static_cast<float>(trantorian.getPosition().getX()) - 0.5f, 0.25f,
                    static_cast<float>(trantorian.getPosition().getY()) - 0.5f},
                {static_cast<float>(trantorian.getPosition().getX()) + 0.5f, 1.25f,
                    static_cast<float>(trantorian.getPosition().getY()) + 0.5f}
            };

            if (_hoveredTrantorian != nullptr && (_hoveredTrantorian->getId() == trantorian.getId())) {
                DrawBoundingBox(box, RED);
            }
        }
    }
}

void Display::DrawTileInfo()
{
    if (_selectedTile != nullptr && _selectedTrantorian == nullptr) {
        int yPosition = 360;

        DrawRectangle(10, 290, 300, 250, Fade(BLACK, 0.5f));
        DrawText(TextFormat("Tile Position: (X: %d, Y: %d)",
            _selectedTile->getPosition().getX(),
            _selectedTile->getPosition().getY()), 20, 300, 20, WHITE);
        DrawText("Items:", 20, 330, 20, WHITE);
        for (auto& object : _selectedTile->getObjects()) {
            DrawText(TextFormat("%s: %d", object->getName().c_str(),
                object->getQuantity()), 20, yPosition, 20, WHITE);
            yPosition += 30;
        }
    }
}

void Display::DrawTrantorianInfo()
{
    if (_selectedTrantorian != nullptr && _selectedTile == nullptr) {
        int yPosition = 360;

        DrawRectangle(10, 290, 300, 250, Fade(BLACK, 0.5f));
        DrawText(TextFormat("Trantorian ID: %s",
            _selectedTrantorian->getId().c_str()), 20, 300, 20, WHITE);
        DrawText(TextFormat("Position: (X: %d, Y: %d)",
            _selectedTrantorian->getPosition().getX(),
            _selectedTrantorian->getPosition().getY()), 20, 330, 20, WHITE);
        // DrawText(TextFormat("Team: %s",
        //     _selectedTrantorian->getTeam()->getName().c_str()), 20, 360, 20, WHITE);
        DrawText(TextFormat("Level: %d",
            _selectedTrantorian->getLevel()), 20, 390, 20, WHITE);
        DrawText("Inventory:", 20, 420, 20, WHITE);
        for (auto& object : _selectedTrantorian->getInventory()) {
            DrawText(TextFormat("%s: %d", object->getName().c_str(),
                object->getQuantity()), 20, yPosition, 20, WHITE);
            yPosition += 30;
        }
    }
}

void Display::DrawObjects(std::list<IObject*> objects)
{
    std::unordered_map<int, std::pair<float, float>> typeOffsets = {
        {Trantorian::ResourceType::FOOD, {0.0f, 0.0f}},
        {Trantorian::ResourceType::LINEMATE, {-0.3f, -0.3f}},
        {Trantorian::ResourceType::DERAUMERE, {0.3f, 0.3f}},
        {Trantorian::ResourceType::SIBUR, {-0.3f, 0.3f}},
        {Trantorian::ResourceType::MENDIANE, {0.3f, -0.3f}},
        {Trantorian::ResourceType::PHIRAS, {-0.2f, 0.0f}},
        {Trantorian::ResourceType::THYSTAME, {0.2f, 0.0f}}
    };

    std::unordered_map<int, Color> typeColors = {
        {Trantorian::ResourceType::FOOD, RED},
        {Trantorian::ResourceType::LINEMATE, BROWN},
        {Trantorian::ResourceType::DERAUMERE, BLUE},
        {Trantorian::ResourceType::SIBUR, YELLOW},
        {Trantorian::ResourceType::MENDIANE, ORANGE},
        {Trantorian::ResourceType::PHIRAS, PURPLE},
        {Trantorian::ResourceType::THYSTAME, PINK}
    };

    for (auto& object : objects) {
        auto offset = typeOffsets[object->getType()];
        auto color = typeColors[object->getType()];
        float posX = static_cast<float>(object->getPosition().getX())
            + offset.first;
        float posZ = static_cast<float>(object->getPosition().getY())
            + offset.second;
        float scale = 0.06f + 0.07f * object->getQuantity();
        DrawCube({posX, 0.5f, posZ}, scale, scale, scale, color);
    }
}

void Display::DrawScoreBoard(Teams &teams)
{
    if (IsKeyDown(KEY_TAB)) {
        const int lineHeight = 30;
        const int padding = 10;
        const int width = 525;
        int totalLines = 1;
        int yPosition = 50;

        for (const auto& team : teams.getTeamsList()) {
            totalLines += 1;
            totalLines += team.getTrantorianList().size();
        }
        int rectangleHeight = totalLines * lineHeight + 2 * padding;

        DrawRectangle(10, 10, width, rectangleHeight, Fade(BLACK, 0.5f));
        DrawText("Scoreboard", 20, 20, 20, GREEN);
        for (const auto& team : teams.getTeamsList()) {
            DrawText(TextFormat("Team: %s", team.getName().c_str()), 20, yPosition, 20, WHITE);
            yPosition += lineHeight;
            for (auto& trantorian : team.getTrantorianList()) {
                DrawText(TextFormat("ID: %s, Level: %d, Position: (%d, %d), TTL: %d",
                    trantorian.getId().c_str(), trantorian.getLevel(),
                    trantorian.getPosition().getX(), trantorian.getPosition().getY(),
                    trantorian.getLifetime()), 20, yPosition, 20, WHITE);
                yPosition += lineHeight;
            }
        }
    }
}

void Display::displayElements()
{
    detectHoveredTile(_camera, _world);
    detectHoveredTrantorian(_camera, _teams);

    BeginDrawing();
    ClearBackground(BLUE);
    BeginMode3D(_camera);
    DrawTiles(_world.getTiles());
    DrawClouds();
    DrawTrantorians(_teams.getTeamsList());
    DrawObjects(_world.getObjects());
    EndMode3D();
    DrawFPS(10, 10);
    DrawTileInfo();
    DrawTrantorianInfo();
    DrawScoreBoard(_teams);
    EndDrawing();
}

std::vector<Model> Display::getClouds() const
{
    return _clouds;
}

void Display::closeWindow()
{
    CloseWindow();
}

bool Display::windowShouldClose()
{
    return WindowShouldClose();
}

void Display::updateCamera()
{
    UpdateCamera(&_camera, CAMERA_FREE);
}

void Display::cleanupModels()
{
    for (auto &model : _clouds) {
        UnloadModel(model);
    }
    _clouds.clear();

    for (auto &team : _teams.getTeamsList()) {
        for (auto &trantorian : team.getTrantorianList()) {
            UnloadModel(trantorian.getModel());
        }
    }
}
