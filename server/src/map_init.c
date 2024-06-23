/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

map_t *init_map(size_t width, size_t height)
{
    map_t *map = malloc(sizeof(map_t));

    map->width = width;
    map->height = height;
    map->tiles = array_constructor(sizeof(tile_t), (void *)&destroy_tile);
    for (size_t y = 0; y < height; y++) {
            for (size_t x = 0; x < width; x++) {
                    array_push_back(map->tiles, init_tile(x, y));
                }
        }
    return map;
}

tile_t *init_tile(size_t x, size_t y)
{
    tile_t *tile = malloc(sizeof(tile_t));

    tile->coordinates.x = x;
    tile->coordinates.y = y;
    tile->resources = init_resources();
    tile->eggs = array_constructor(sizeof(egg_t *), NULL);
    return tile;
}

hashmap_t *init_resources(void)
{
    hashmap_t *resources;

    resources = create_hashmap();
    hashmap_put(resources, "food", 0);
    hashmap_put(resources, "linemate", 0);
    hashmap_put(resources, "deraumere", 0);
    hashmap_put(resources, "sibur", 0);
    hashmap_put(resources, "mendiane", 0);
    hashmap_put(resources, "phiras", 0);
    hashmap_put(resources, "thystame", 0);
    return resources;
}
