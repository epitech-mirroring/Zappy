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

static void update_egg_count(game_t *game, hashmap_t **content, tile_t *tile)
{
    egg_t *egg = NULL;
    int eggs_number = 0;
    size_t size = array_get_size(game->eggs);

    for (size_t i = 0; i < size ; i++) {
        egg = (egg_t *)array_get_at(game->eggs, i);
        if (egg->coordinates.x == tile->coordinates.x
            && egg->coordinates.y == tile->coordinates.y)
            eggs_number++;
    }
    hashmap_set(*content, "egg", eggs_number);
}

static char *make_msg(char *msg, char *element)
{
    if (strlen(msg) == 0)
        snprintf(msg, 100000, "%s", element);
    else
        snprintf(msg, 100000, "%s %s,", strdup(msg), element);
    return msg;
}

char *look_north(game_t *game, short level,
    coordinates_t player_coordinates, hashmap_t *content)
{
    char *msg = calloc(100000, sizeof(char));
    int x = 0;
    int y = player_coordinates.y;
    tile_t *tile = NULL;

    for (short i = 0; i <= level; i++) {
        x = player_coordinates.x - i;
        y = manage_pos(y, game->map->height);
        for (size_t j = 0; j < (size_t)1 + (i * 2); j++) {
            x = manage_pos(x, game->map->width);
            tile = get_tile(game->map, x, y);
            update_egg_count(game, &content, tile);
            msg = make_msg(msg, get_element_on_tile
                (tile, content));
            x++;
        }
        y--;
    }
    return msg;
}

char *look_south(game_t *game, short level,
    coordinates_t player_coordinates, hashmap_t *content)
{
    char *msg = calloc(100000, sizeof(char));
    int x = 0;
    int y = player_coordinates.y;
    tile_t *tile = NULL;

    for (short i = 0; i <= level; i++) {
        x = player_coordinates.x + i;
        y = manage_pos(y, game->map->height);
        for (size_t j = 0; j < (size_t)1 + (i * 2); j++) {
            x = manage_pos(x, game->map->width);
            tile = get_tile(game->map, x, y);
            update_egg_count(game, &content, tile);
            msg = make_msg(msg, get_element_on_tile
                (tile, content));
            x--;
        }
        y++;
    }
    return msg;
}

char *look_west(game_t *game, short level,
    coordinates_t player_coordinates, hashmap_t *content)
{
    char *msg = calloc(100000, sizeof(char));
    int x = player_coordinates.x;
    int y = 0;
    tile_t *tile = NULL;

    for (short i = 0; i <= level; i++) {
        y = player_coordinates.x + i;
        x = manage_pos(y, game->map->height);
        for (size_t j = 0; j < (size_t)1 + (i * 2); j++) {
            y = manage_pos(x, game->map->width);
            tile = get_tile(game->map, x, y);
            update_egg_count(game, &content, tile);
            msg = make_msg(msg, get_element_on_tile
                (tile, content));
            y--;
        }
        x--;
    }
    return msg;
}

char *look_east(game_t *game, short level,
    coordinates_t player_coordinates, hashmap_t *content)
{
    char *msg = calloc(100000, sizeof(char));
    int x = player_coordinates.x;
    int y = 0;
    tile_t *tile = NULL;

    for (short i = 0; i <= level; i++) {
        y = player_coordinates.x - i;
        x = manage_pos(y, game->map->height);
        for (size_t j = 0; j < (size_t)1 + (i * 2); j++) {
            y = manage_pos(x, game->map->width);
            tile = get_tile(game->map, x, y);
            update_egg_count(game, &content, tile);
            msg = make_msg(msg, get_element_on_tile
                (tile, content));
            y++;
        }
        x++;
    }
    return msg;
}
