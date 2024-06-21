/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <string.h>
#include "game.h"
#include "actions.h"
#include "ia_actions/look.h"

static int manage_pos(int index, int max)
{
    if (index < 0)
        return max + (index % max);
    if (index == max)
        return index % max;
    return index;
}

char *look_north(game_t *game, short level,
    coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    int x = player_coordinates.x;
    int y = player_coordinates.y;

    for (size_t i = 0; i <= level; i++) {
        x = player_coordinates.x - i;
        y = manage_pos(y, game->map->height);
        for (size_t j = 0; j < 1 + (i * 2); j++) {
            x = manage_pos(x, game->map->width);
            snprintf(msg, 100000, "%s%s,", strdup(msg), get_element_on_tile
                (game, get_tile(game->map, x, y)));
            x++;
        }
        y--;
    }
    return msg;
}

char *look_south(game_t *game, short level,
    coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    coordinates_t *coord = calloc(100, sizeof(coordinates_t));
    int x = player_coordinates.x;
    int y = player_coordinates.y;
    int k = 0;

    for (size_t i = 0; i <= level; i++) {
        x = player_coordinates.x + i;
        y = manage_pos(y, game->map->height);
        for (size_t j = 0; j < 1 + (i * 2); j++) {
            x = manage_pos(x, game->map->width);
            coord[k] = (coordinates_t){x, y};
            snprintf(msg, 100000, "%s%s,", strdup(msg), get_element_on_tile
                (game, get_tile(game->map, x, y), coord, &k));
            x--;
        }
        y++;
    }
    free(coord);
    return msg;
}

char *look_west(game_t *game, short level,
    coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    coordinates_t *coord = calloc(100, sizeof(coordinates_t));
    int x = player_coordinates.x;
    int y = player_coordinates.y;
    int k = 0;

    for (size_t i = 0; i <= level; i++) {
        y = player_coordinates.x + i;
        x = manage_pos(y, game->map->height);
        for (size_t j = 0; j < 1 + (i * 2); j++) {
            y = manage_pos(x, game->map->width);
            coord[k] = (coordinates_t){x, y};
            snprintf(msg, 100000, "%s%s,", strdup(msg), get_element_on_tile
                (game, get_tile(game->map, x, y), coord, &k));
            y--;
        }
        x--;
    }
    free(coord);
    return msg;
}

char *look_east(game_t *game, short level,
    coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    coordinates_t *coord = calloc(100, sizeof(coordinates_t));
    int x = player_coordinates.x;
    int y = player_coordinates.y;
    int k = 0;

    for (size_t i = 0; i <= level; i++) {
        y = player_coordinates.x - i;
        x = manage_pos(y, game->map->height);
        for (size_t j = 0; j < 1 + (i * 2); j++) {
            y = manage_pos(x, game->map->width);
            coord[k] = (coordinates_t){x, y};
            snprintf(msg, 100000, "%s%s,", strdup(msg), get_element_on_tile
                (game, get_tile(game->map, x, y), coord, &k));
            y++;
        }
        x++;
    }
    free(coord);
    return msg;
}
