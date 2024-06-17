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

resources_t init_resources(void)
{
    resources_t resources;

    resources.food_count = 0;
    resources.linemate_count = 0;
    resources.deraumere_count = 0;
    resources.sibur_count = 0;
    resources.mendiane_count = 0;
    resources.phiras_count = 0;
    resources.thystame_count = 0;
    return resources;
}
