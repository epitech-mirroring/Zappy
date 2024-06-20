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

char *look_north(game_t *game, short level,
                           coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    array_t *tiles = array_constructor(sizeof(tile_t), (void * )&free);
    int x = 0;
    int y = 0;
    int  current_line_size = 1;

    for (size_t i = 0; i < level; i++) {
            y = player_coordinates.y + i;
            for (int j = (-current_line_size/2); j < (current_line_size/2)+1; j++) {
                    x = player_coordinates.x + j;
                    if (x < 0)
                        x = game->map->width + x;
                    if (y < 0)
                        y = game->map->height + y;
                    if (x >= game->map->width)
                        x -= game->map->width;
                    if (y >= game->map->height)
                        y -= game->map->height;
                    snprintf(msg, 100000, "[%s%s]", msg,
                             get_element_on_tile(game, &tiles, x, y));
                }
            current_line_size++;
        }
    return msg;
}

char *look_south(game_t *game, short level,
                           coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    array_t *tiles = array_constructor(sizeof(tile_t), (void * )&free);
    int x = 0;
    int y = 0;
    int  current_line_size = 1;

    for (size_t i = 0; i < level; i++) {
            y = player_coordinates.y - i;
            for (int j = (-current_line_size/2); j < (current_line_size/2)+1; j++) {
                    x = player_coordinates.x + j;
                    if (x < 0)
                        x = game->map->width + x;
                    if (y < 0)
                        y = game->map->height + y;
                    if (x >= game->map->width)
                        x -= game->map->width;
                    if (y >= game->map->height)
                        y -= game->map->height;
                    snprintf(msg, 100000, "%s%s", msg,
                             get_element_on_tile(game, &tiles, x, y));
                }
            current_line_size++;
        }
    return msg;
}

char *look_west(game_t *game, short level,
                          coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    array_t *tiles = array_constructor(sizeof(tile_t), (void * )&free);
    int x = 0;
    int y = 0;
    int  current_line_size = 1;

    for (size_t i = 0; i < level; i++) {
            x = player_coordinates.x - i;
            for (int j = (-current_line_size/2); j < (current_line_size/2)+1; j++) {
                    y = player_coordinates.y + j;
                    if (x < 0)
                        x = game->map->width + x;
                    if (y < 0)
                        y = game->map->height + y;
                    if (x >= game->map->width)
                        x -= game->map->width;
                    if (y >= game->map->height)
                        y -= game->map->height;
                    snprintf(msg, 100000, "%s%s", msg,
                             get_element_on_tile(game, &tiles, x, y));
                }
            current_line_size++;
        }
        return msg;
}

char *look_east(game_t *game, short level,
                          coordinates_t player_coordinates)
{
    char *msg = calloc(100000, sizeof(char));
    array_t *tiles = array_constructor(sizeof(tile_t), (void * )&free);
    int x = 0;
    int y = 0;
    int  current_line_size = 1;

    for (size_t i = 0; i < level; i++) {
            x = player_coordinates.x + i;
            for (int j = (-current_line_size/2); j < (current_line_size/2)+1; j++) {
                    y = player_coordinates.y + j;
                    if (x < 0)
                        x = game->map->width + x;
                    if (y < 0)
                        y = game->map->height + y;
                    if (x >= game->map->width)
                        x -= game->map->width;
                    if (y >= game->map->height)
                        y -= game->map->height;
                    snprintf(msg, 100000, "%s%s", msg,
                             get_element_on_tile(game, &tiles, x, y));
                }
            current_line_size++;
        }
    return msg;
}
