/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Events
*/

#ifndef EVENTS_HPP_
    #define EVENTS_HPP_

    #include "tiles/Tile.hpp"
    #include "world/World.hpp"

    #include <raylib.h>
    #include <iostream>
    #include <vector>
    #include <algorithm>

namespace GUI {
    class Events {
    public:
        Events() = default;
        ~Events() = default;

        bool CheckCollisionRayBox(Ray ray, BoundingBox box);

        void detectHoveredTile(Camera _camera, World &_world);

    protected:
        Tile* _selectedTile = nullptr;           // Selected tile
        Tile* _hoveredTile = nullptr;            // Selected tile
    };
} // namespace GUI //
#endif /* !EVENTS_HPP_ */
