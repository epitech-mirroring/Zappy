/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "map.h"
#include <string.h>
#include <stdio.h>

char *tile_to_string(tile_t *tile)
{
    char *str = calloc(1024, sizeof(char));

    if (tile == NULL) {
        sprintf(str, "sbp\n");
        return str;
    }
    sprintf(str, "bct %li %li %i %i %i %i %i %i %i\n", tile->coordinates.x,
        tile->coordinates.y, hashmap_get(tile->resources, "food"),
        hashmap_get(tile->resources, "linemate"), hashmap_get(
            tile->resources, "deraumere"), hashmap_get(
            tile->resources, "sibur"), hashmap_get(
            tile->resources, "mendiane"), hashmap_get(
            tile->resources, "phiras"), hashmap_get(
            tile->resources, "thystame"));
    return str;
}

char *map_to_string(map_t *map)
{
    char *str = calloc(map->width * map->height * 1024, sizeof(char));
    char *tmp = NULL;
    char *prev = NULL;
    tile_t *tile = NULL;

    printf("map->width: %lu\n", map->width);
    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            tile = get_tile(map, x, y);
            tmp = tile_to_string(tile);
            prev = strdup(str);
            sprintf(str, "%s%s", prev, tmp);
            free(tmp);
            free(prev);
        }
    }
    return str;
}

char *map_dimensions_to_string(map_t *map)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "msz %li %li\n", map->width, map->height);
    return str;
}
