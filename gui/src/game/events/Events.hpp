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
    #include "trantorians/Teams.hpp"

    #include <raylib.h>
    #include <iostream>
    #include <vector>
    #include <algorithm>

namespace GUI {
    class Events {
    public:
        Events();
        ~Events() = default;

        bool CheckCollisionRayBox(Ray ray, BoundingBox box);

        void detectHoveredTile(Camera _camera, World &_world);

        void detectHoveredTrantorian(Camera _camera, Teams &_teams);

    protected:
        Tile* _selectedTile;
        Tile* _hoveredTile;

        Trantorian* _selectedTrantorian;
        Trantorian* _hoveredTrantorian;
    };
} // namespace GUI
#endif /* !EVENTS_HPP_ */
