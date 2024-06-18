/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void msz_log_gui(game_t *game)
{
    char *str = map_dimensions_to_string(game->map);

    array_push_back(game->gui_log, str);
    free(str);
}

void bct_log_gui(game_t *game, coordinates_t coordinates)
{
    char *str = map_tile_to_string(game->map, coordinates);

    array_push_back(game->gui_log, str);
    free(str);
}

void mct_log_gui(game_t *game)
{
    char *str = map_to_string(game->map);

    array_push_back(game->gui_log, str);
    free(str);
}
