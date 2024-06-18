/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "map.h"

void msz_log_gui(game_t *game, char *arg)
{
    char *str = map_dimensions_to_string(game->map);

    array_push_back(game->gui_log, str);
}

void bct_log_gui(game_t *game, char *arg)
{
    coordinates_t coordinates = {0, 0};
    char *str = NULL;

    str = tile_to_string(get_tile_by_coordinates(game->map, coordinates));
    array_push_back(game->gui_log, str);
}

void mct_log_gui(game_t *game, char *arg)
{
    char *str = map_to_string(game->map);

    array_push_back(game->gui_log, str);
}
