/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "map.h"
#include "egg.h"

static void generate_stones(map_t *map, int x, int y)
{
    for (int i = 0; i < (map->height * map->width) / 10; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.mendiane_count += 1;
    }
    for (int i = 0; i < (map->height * map->width) / 8; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.phiras_count += 1;
    }
    for (int i = 0; i < (map->height * map->width) / 5; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.thystame_count += 1;
    }
    for (int i = 0; i < (map->height * map->width) / 10; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.sibur_count += 1;
    }
}

void generate_ressources(map_t *map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < (map->height * map->width) / 50; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.food_count += 1;
    }
    for (int i = 0; i < (map->height * map->width) / 30; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.linemate_count += 1;
    }
    for (int i = 0; i < (map->height * map->width) / 15; i++) {
        x = rand() % map->width;
        y = rand() % map->height;
        get_tile(map, x, y)->resources.deraumere_count += 1;
    }
    generate_stones(map, x, y);
}

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
