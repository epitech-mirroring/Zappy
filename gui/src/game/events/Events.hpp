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
        /**
         * @brief Construct a new Events object
         */
        Events();
        /**
         * @brief Destroy the Events object
         */
        ~Events() = default;

        /**
         * @brief Detect the hovered tile
         * @param _camera camera object
         * @param _world world object
         */
        void detectHoveredTile(Camera _camera, World &_world);
        /**
         * @brief Detect the selected tile
         * @param _camera camera object
         * @param _world world object
         */
        void detectHoveredTrantorian(Camera _camera, Teams &_teams);

    protected:
        Tile* _selectedTile;                // tile selected by the user
        Tile* _hoveredTile;                 // tile hovered by the user

        Trantorian* _selectedTrantorian;    // trantorian selected by the user
        Trantorian* _hoveredTrantorian;     // trantorian hovered by the user
    };
} // namespace GUI //
#endif /* !EVENTS_HPP_ */
