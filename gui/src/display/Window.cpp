/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Window
*/

#include "Window.hpp"

GUI::Window::Window(int width, int height, std::string winName)
{
    _width = width;
    _height = height;
    _winName = winName;
}

void GUI::Window::displayWindow()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(_width, _height, _winName.c_str());
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
}
