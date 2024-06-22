/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "map.h"

void msz_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = map_dimensions_to_string(game->map);

    buffer_write(client->buffer_answered, str);
}

void bct_log_gui(game_t *game, char *arg, client_t *client)
{
    coordinates_t coordinates = {0, 0};
    char *str = NULL;

    str = tile_to_string(get_tile_by_coordinates(game->map, coordinates));
    buffer_write(client->buffer_answered, str);
}

void mct_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = map_to_string(game->map);

    buffer_write(client->buffer_answered, str);
}
