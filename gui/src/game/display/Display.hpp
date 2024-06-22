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
    #include <cstring>

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
         * @brief calls all the draw functions
         */
        void displayElements();

        /**
         * @brief Draw the tiles
         * @param tiles 2D vector of tiles
         */
        void DrawTiles(std::vector<std::vector<Tile>> tiles);
        /**
         * @brief Draw the clouds
         */
        void DrawClouds();
        /**
         * @brief Draw the trantorians /!\ TO FIX /!\
         * @param teams list of teams
         */
        void DrawTrantorians(std::list<Teams> teams);
        /**
         * @brief Draw the tile info (list of items, position)
         */
        void DrawTileInfo();
        /**
         * @brief Draw the trantorian info (team, time to live, level, inventory, position, id)
         */
        void DrawTrantorianInfo();
        /**
         * @brief Draw the objects (food, linemate, deraumere, sibur, mendiane, phiras, thystame)
         * if there is many obj we just have bigger squares
         * @param objects list of objects
         */
        void DrawObjects(std::list<IObject*> objects);
        /**
         * @brief Draw the egg
         */
        void DrawEgg();
        /**
         * @brief Draw the ScoreBoard
         */
        void DrawScoreBoard(Teams &teams);
        /**
         * @brief Cleanup the models /!\ ADD TRANTORIANS /!\
         */
        void cleanupModels();
        /**
         * @brief Initialize the clouds
         */
        void initClouds();

        /**
         * @brief Check if the window should close
         * @return true if the window should close
         */
        bool windowShouldClose();
        /**
         * @brief Update the camera
         */
        void updateCamera();
        /**
         * @brief Close the window
         */
        void closeWindow();

        /**
         * @brief Get the Camera object
         * @return Camera object
         */
        std::vector<Model> getClouds() const;

        /**
         * @brief Draw the SST Box
         */
        void DrawSSTBox();

        /**
         * @brief Draw the TextBox
         */
        std::string getNewTimeUnit();

        /**
         * @brief Display the help menu
         */
        void DisplayHelpMenu();

        /**
         * @brief Display the game informations on the top right corner
         */
        void DisplayGameInformations();

        /**
         * @brief setTheTimeUnit
         */
        void setTimeUnit(unsigned int timeUnit);

        /**
         * @brief Set the new time unit
         */
        void setNewTimeUnit(std::string newTimeUnit);

        void addLog(const std::string& log);
        void DrawLogs();

    protected:
        Camera _camera;                          // Camera
        std::vector<Model> _clouds;              // Clouds models
        std::vector<Vector3> _cloudPositions;    // Clouds positions
        World &_world;                           // World
        Teams &_teams;                           // Teams
        unsigned int _timeUnit;                  // Time unit

        char _inputText[256] = "";
        bool _textBoxActive = false;
        int _framesCounter = 0;
        int _ignoreInputFrames = 0;
        std::string _newTimeUnit;
        bool _gameInfo = false;
        bool _drawLogs = false;
        std::vector<std::string> _logs;
    };
}

#endif // DISPLAY_HPP_
