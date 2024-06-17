/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "map.h"

char *tile_to_string(tile_t *tile)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "bct %i %i %i %i %i %i %i %i %i\n", tile->coordinates.x,
        tile->coordinates.y, tile->resources.food_count,
        tile->resources.linemate_count, tile->resources.deraumere_count,
        tile->resources.sibur_count, tile->resources.mendiane_count,
        tile->resources.phiras_count, tile->resources.thystame_count);
    return str;
}

char *map_to_string(map_t *map)
{
    char *str = calloc(1024, sizeof(char));
    tile_t *tile = NULL;

    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            tile = array_get(map->tiles, x + y * map->width);
            strcat(str, tile_to_string(tile));
        }
    }
    return str;
}

char *map_dimensions_to_string(map_t *map)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "msz %i %i\n", map->width, map->height);
    return str;
}
