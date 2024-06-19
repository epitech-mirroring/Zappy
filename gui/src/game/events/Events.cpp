/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Events
*/

#include "Events.hpp"

using namespace GUI;

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
    _hoveredTile = nullptr;
    Vector2 mousePosition = GetMousePosition();
    Ray ray = GetMouseRay(mousePosition, _camera);

    for (auto& tiles : _world.getTiles()) {
        for (auto& tile : tiles) {
            BoundingBox box = {
                {static_cast<float>(tile.getPosition().getX()) - 0.5f, 0.0f,
                    static_cast<float>(tile.getPosition().getY()) - 0.5f},
                {static_cast<float>(tile.getPosition().getX()) + 0.5f, 1.0f,
                    static_cast<float>(tile.getPosition().getY()) + 0.5f}
            };
            if (CheckCollisionRayBox(ray, box)) {
                _hoveredTile = &tile;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    _selectedTile = &tile;
                break;
            }
        }
        if (_hoveredTile != nullptr)
            break;
    }
}
