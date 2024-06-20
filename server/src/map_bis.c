/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "map.h"
#include "egg.h"

tile_t *init_tile(size_t x, size_t y)
{
    tile_t *tile = malloc(sizeof(tile_t));

    tile->coordinates.x = x;
    tile->coordinates.y = y;
    tile->resources = init_resources();
    tile->eggs = array_constructor(sizeof(egg_t *), (void *)&destroy_egg);
    return tile;
}

void destroy_tile(tile_t *tile)
{
    array_destructor(tile->eggs);
    free(tile);
}

hashmap_t *init_resources(void)
{
    hashmap_t *resources;

    resources = create_hashmap();
    hashmap_put(resources, "food", 10);
    hashmap_put(resources, "linemate", 0);
    hashmap_put(resources, "deraumere", 0);
    hashmap_put(resources, "sibur", 0);
    hashmap_put(resources, "mendiane", 0);
    hashmap_put(resources, "phiras", 0);
    hashmap_put(resources, "thystame", 0);
    return resources;
}
