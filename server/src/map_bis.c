/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

tile_t *init_tile(size_t x, size_t y)
{
    tile_t *tile = malloc(sizeof(tile_t));

    tile->coordinates.x = x;
    tile->coordinates.y = y;
    tile->resources = init_resources();
    tile->eggs = array_constructor(sizeof(egg_t *), NULL);
    return tile;
}

void destroy_tile(tile_t *tile)
{
    destroy_hashmap(tile->resources);
    array_destructor(tile->eggs);
    free(tile);
}

hashmap_t *init_resources(void)
{
    hashmap_t *resources;

    resources = create_hashmap();
    hashmap_put(resources, "food", 0);
    hashmap_put(resources, "linemate", 10);
    hashmap_put(resources, "deraumere", 0);
    hashmap_put(resources, "sibur", 0);
    hashmap_put(resources, "mendiane", 0);
    hashmap_put(resources, "phiras", 0);
    hashmap_put(resources, "thystame", 0);
    return resources;
}

void update_pos(coordinates_t prev, coordinates_t now, map_t *map)
{
    tile_t *prev_tile = get_tile_by_coordinates(map, prev);
    tile_t *now_tile = get_tile_by_coordinates(map, now);

    prev_tile->player_count--;
    now_tile->player_count++;
}

void player_spawn(egg_t *egg, team_t *team, game_t *game, size_t i)
{
    coordinates_t pos = egg->coordinates;
    tile_t *tile = get_tile_by_coordinates(game->map, pos);

    tile->player_count++;
    array_remove(game->eggs, i);
    destroy_egg(egg);
    team->free_places--;
}
