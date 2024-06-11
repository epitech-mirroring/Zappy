/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include <raylib.h>
    #include "objects/eggs/Egg.hpp"
    #include "objects/food/Food.hpp"
    #include "objects/stones/Deraumere.hpp"
    #include "objects/stones/Linemate.hpp"
    #include "objects/stones/Mendiane.hpp"
    #include "objects/stones/Phiras.hpp"
    #include "objects/stones/Sibur.hpp"
    #include "objects/stones/Thystame.hpp"
    #include "trantorians/Trantorian.hpp"
    #include "world/World.hpp"

namespace GUI
{
    class Window
    {
        public:
            /**
             * @brief Create window object
             */
            Window(int width = 1270, int height = 720,
                std::string winName = "Zappy - {Epitech_Year_End_Project}");
            /**
             * @brief Destroy window object
             */
            ~Window() = default;

            /**
             * @brief Display window
             */
            void displayWindow();

        private:
            int _width;
            int _height;
            std::string _winName;
    };
} // namespace GUI

#endif //WINDOW_HPP_
