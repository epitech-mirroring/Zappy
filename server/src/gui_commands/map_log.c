/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "map.h"
#include <sys/socket.h>
#include <string.h>

void msz_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = map_dimensions_to_string(game->map);

    (void)arg;
    buffer_write(client->buffer_answered, str);
}

void bct_log_gui(game_t *game, char *arg, client_t *client)
{
    coordinates_t coordinates = {0, 0};
    char *str = NULL;
    int x = 0;
    int y = 0;

    sscanf(arg, "%d %d", &x, &y);
    if (x < 0 || y < 0 || x >= (int)game->map->width
        || y >= (int)game->map->height) {
        buffer_write(client->buffer_answered, "sbp\n");
        return;
    }
    str = tile_to_string(get_tile_by_coordinates(game->map, coordinates));
    buffer_write(client->buffer_answered, str);
}

void mct_log_gui(game_t *game, char *arg, client_t *client)
{
    tile_t *tile = NULL;
    char *str = NULL;

    (void)arg;
    for (size_t y = 0; y < game->map->height; y++) {
        for (size_t x = 0; x < game->map->width; x++) {
            tile = get_tile_by_coordinates(game->map, (coordinates_t){x, y});
            str = tile_to_string(tile);
            send(client->socket, str, strlen(str), MSG_NOSIGNAL);
            free(str);
        }
    }
}
