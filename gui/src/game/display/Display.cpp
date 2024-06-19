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

Display::~Display()
{
    cleanupModels();
    CloseWindow();
}

void Display::cleanupModels()
{
    for (auto &model : _clouds) {
        UnloadModel(model);
    }
    _clouds.clear();
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

void Display::DrawTrantorians()
{
    for (auto &team : Teams::getTeamsList()) {
        for (auto &trantorian : team.getTrantorianList()) {
            Vector3 position = {
                static_cast<float>(trantorian.getPosition().getX()),
                0.5f,
                static_cast<float>(trantorian.getPosition().getY())
            };

            Vector3 rotationAxis = {0.0f, 1.0f, 0.0f};
            Vector3 scale = {1.0f, 1.0f, 1.0f};

            DrawModelEx(trantorian.getModel(), position, rotationAxis, trantorian.getOrientation(), scale, WHITE);
            std::cout << "GUI LOG: Player " << trantorian.getId() << " drawn" << std::endl;
        }
    }
}

void Display::DrawTileInfo()
{
    if (_selectedTile != nullptr) {
        DrawRectangle(10, GetScreenHeight() - 110, 300, 100, Fade(BLACK, 0.5f));
        DrawText(TextFormat("Tile Position: (%d, %d)", _selectedTile->getPosition().getX(),
            _selectedTile->getPosition().getY()), 20, GetScreenHeight() - 100, 20, WHITE);
        DrawText("Additional data here", 20, GetScreenHeight() - 70, 20, WHITE);
    }
}

bool Display::windowShouldClose()
{
    return WindowShouldClose();
}

void Display::updateCamera()
{
    UpdateCamera(&_camera, CAMERA_FREE);
}
void Display::DrawObjects(std::list<IObject*> objects)
{
    // for (auto& object : objects) {
    //     if (object->getType() == Trantorian::ResourceType::FOOD) {
    //         DrawSphere({ static_cast<float>(object->getPosition().getX()), 1.0f,
    //                      static_cast<float>(object->getPosition().getY()) }, 0.03f, RED);
    //     } else {
    //         DrawSphere({ static_cast<float>(object->getPosition().getX()), 1.0f,
    //                      static_cast<float>(object->getPosition().getY()) }, 0.03f, GREEN);
    //     }
    // }
}

void Display::displayElements()
{
    Events::detectHoveredTile(_camera, _world);

    BeginDrawing();
    ClearBackground(BLUE);
    BeginMode3D(_camera);
    DrawTiles(_world.getTiles());
    DrawClouds();
    DrawTrantorians();
    EndMode3D();
    DrawFPS(10, 10);
    DrawTileInfo();
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
