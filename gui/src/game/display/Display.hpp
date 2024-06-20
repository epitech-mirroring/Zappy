/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
    #define DISPLAY_HPP_

    #include <sstream>
    #include <raylib.h>
    #include "world/World.hpp"
    #include "trantorians/Teams.hpp"
    #include "trantorians/Trantorian.hpp"
    #include "game/events/Events.hpp"

namespace GUI {
    class Display : public Events {
    public:
        /**
         * @brief Construct a new Display object
         * @param world World object reference
         * @param teams teams object reference
         */
        Display(World &world, Teams &teams);
        /**
         * @brief Destroy the Display object
        */
        ~Display() = default;

        void displayElements();

        void DrawTiles(std::vector<std::vector<Tile>> tiles);
        void DrawClouds();
        void DrawTrantorians();
        void DrawTileInfo();
        void DrawTrantorianInfo();
        void DrawObjects(std::list<IObject*> objects);
        void DrawEgg();

        void cleanupModels();
        void initClouds();

        bool windowShouldClose();
        void updateCamera();

        void closeWindow();

        std::vector<Model> getClouds() const;

    protected:
        Camera _camera;     // Camera
        std::vector<Model> _clouds;              // Clouds models
        std::vector<Vector3> _cloudPositions;    // Clouds positions
        World &_world;      // World
        Teams &_teams;      // Teams
    };
}

#endif // DISPLAY_HPP_
