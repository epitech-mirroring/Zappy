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
      _selectedTrantorian(nullptr), _hoveredTrantorian(nullptr) {}

bool Events::CheckCollisionRayBox(Ray ray, BoundingBox box)
{
    float tmin = (box.min.x - ray.position.x) / ray.direction.x;
    float tmax = (box.max.x - ray.position.x) / ray.direction.x;

    if (tmin > tmax) std::swap(tmin, tmax);

    float tymin = (box.min.y - ray.position.y) / ray.direction.y;
    float tymax = (box.max.y - ray.position.y) / ray.direction.y;

    if (tymin > tymax) std::swap(tymin, tymax);
    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (box.min.z - ray.position.z) / ray.direction.z;
    float tzmax = (box.max.z - ray.position.z) / ray.direction.z;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);
    if ((tmin > tzmax) || (tzmin > tmax))
        return false;
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;
    return true;
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
            if (CheckCollisionRayBox(ray, box)) {
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
            if (CheckCollisionRayBox(ray, box)) {
                _hoveredTrantorian = &trantorian;
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
