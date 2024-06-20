/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Events
*/

#include "Events.hpp"

using namespace GUI;

Events::Events()
    : _selectedTile(nullptr), _hoveredTile(nullptr),
      _selectedTrantorian(nullptr), _hoveredTrantorian(nullptr)
{
}

void Events::detectHoveredTile(Camera _camera, World &_world)
{
    if (_hoveredTrantorian != nullptr || IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
            _selectedTile = nullptr;
        return;
    }

    _hoveredTile = nullptr;
    Vector2 mousePosition = GetMousePosition();
    Ray ray = GetMouseRay(mousePosition, _camera);

    for (auto &row : _world.getTiles()) {
        for (auto &tile : row) {
            BoundingBox box = {
                {static_cast<float>(tile.getPosition().getX()) - 0.5f, 0.0f,
                    static_cast<float>(tile.getPosition().getY()) - 0.5f},
                {static_cast<float>(tile.getPosition().getX()) + 0.5f, 1.0f,
                    static_cast<float>(tile.getPosition().getY()) + 0.5f}
            };

            RayCollision collision = GetRayCollisionBox(ray, box);
            if (collision.hit) {
                _hoveredTile = &tile;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    _selectedTile = &tile;
                    _selectedTrantorian = nullptr;
                }
                break;
            }
        }
        if (_hoveredTile != nullptr)
            break;
    }
}

void Events::detectHoveredTrantorian(Camera _camera, Teams &_teams)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
        _selectedTrantorian = nullptr;
        return;
    }

    _hoveredTrantorian = nullptr;
    Vector2 mousePosition = GetMousePosition();
    Ray ray = GetMouseRay(mousePosition, _camera);

    for (auto& team : _teams.getTeamsList()) {
        for (auto& trantorian : team.getTrantorianList()) {
            BoundingBox box = {
                {static_cast<float>(trantorian.getPosition().getX()) - 0.5f, 0.25f,
                    static_cast<float>(trantorian.getPosition().getY()) - 0.5f},
                {static_cast<float>(trantorian.getPosition().getX()) + 0.5f, 1.25f,
                    static_cast<float>(trantorian.getPosition().getY()) + 0.5f}
            };
            RayCollision collision = GetRayCollisionBox(ray, box);
            if (collision.hit) {
                _hoveredTrantorian = &trantorian;
                // std::cout << "Hovered Trantorian ID: " << trantorian.getId() << std::endl;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    _selectedTrantorian = &trantorian;
                    _selectedTile = nullptr;
                    std::cout << "Selected Trantorian ID: " << trantorian.getId() << std::endl;
                }
                return;
            }
        }
    }
}
