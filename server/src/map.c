/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "map.h"
#include "egg.h"

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

void destroy_map(map_t *map)
{
    if (map == NULL)
        return;
    array_destructor(map->tiles);
    free(map);
}

tile_t *get_tile(map_t *map, size_t x, size_t y)
{
    return (tile_t *)array_get_at(map->tiles, y * map->width + x);
}

tile_t *get_tile_by_coordinates(map_t *map, coordinates_t coordinates)
{
    return get_tile(map, coordinates.x, coordinates.y);
}
