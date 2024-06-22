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

        /**
         * @brief Display all objects to draw on the map
         * @return void (nothing to return)
         */
        void displayElements();

        /**
         * @brief Draw tile's map
         * @param tiles Every informations about tile's map
         * @return void (nothing to return)
         */
        void DrawTiles(std::vector<std::vector<Tile>> tiles);

        /**
         * @brief Draw clouds
         * @return void (nothing to return)
         */
        void DrawClouds();

        /**
         * @brief Draw trantorians
         * @return void (nothing to return)
         */
        void DrawTrantorians();

        /**
         * @brief Draw tile's infos
         * @return void (nothing to return)
         */
        void DrawTileInfo();

        /**
         * @brief Draw trantorian's infos
         * @return void (nothing to return)
         */
        void DrawTrantorianInfo();

        /**
         * @brief Draw food and stone objects
         * @param objects every food and stone objects
         * @return void (nothing to return)
         */
        void DrawObjects(std::list<IObject*> objects);

        /**
         * @brief Draw eggs
         * @return void (nothing to return)
         */
        void DrawEgg();

        /**
         * @brief Draw actions (parse which action to draw)
         * @return void (nothing to return)
         */
        void DrawAction();

        /**
         * @brief Draw expulsion action
         * @return void (nothing to return)
         */
        void DrawExpulsionAction(Trantorian &trantorian);

        /**
         * @brief Draw collect action
         * @return void (nothing to return)
         */
        void DrawCollectAction(Trantorian &trantorian);

        /**
         * @brief Draw drop action
         * @return void (nothing to return)
         */
        void DrawDropAction(Trantorian &trantorian);

        /**
         * @brief Cleanup object's models
         * @return void (nothing to return)
         */
        void cleanupModels();

        /**
         * @brief Init clouds models
         * @return void (nothing to return)
         */
        void initClouds();

        /**
         * @brief Know if window should close
         * @return bool (true if window should close)
         */
        bool windowShouldClose();

        /**
         * @brief Update camera values
         * @return void (nothing to return)
         */
        void updateCamera();

        /**
         * @brief Close the window
         * @return void (nothing to return)
         */
        void closeWindow();

        /**
         * @brief Get clouds models
         * @return list of clouds models
         */
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
