/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "map.h"
#include "egg.h"

const ressources_map_t resources_map[] = {
    { "food", 50 },
    { "linemate", 30 },
    { "deraumere", 15 },
    { "sibur", 10 },
    { "mendiane", 10 },
    { "phiras", 8 },
    { "thystame", 5 },
    { NULL, 0 }
};

void generate_ressources(map_t *map)
{
    tile_t *tile = NULL;
    int nb = 0;
    int nb_ressources = 0;
    size_t x = 0;
    size_t y = 0;

    for (size_t i = 0; resources_map[i].name != NULL; i++) {
        nb_ressources = resources_map[i].density *
            map->width * map->height / 100;
        for (int j = 0; j < nb_ressources; j++) {
            x = rand() % map->width;
            y = rand() % map->height;
            tile = get_tile(map, x, y);
            nb = hashmap_get(tile->resources, resources_map[i].name);
            hashmap_put(tile->resources,
                resources_map[i].name, nb + 1);
        }
    }
}

tile_t *get_tile(map_t *map, size_t x, size_t y)
{
    return (tile_t *)array_get_at(map->tiles, y * map->width + x);
}

tile_t *get_tile_by_coordinates(map_t *map, coordinates_t coordinates)
{
    return get_tile(map, coordinates.x, coordinates.y);
}
