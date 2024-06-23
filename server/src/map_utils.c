/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void destroy_tile(tile_t *tile)
{
    destroy_hashmap(tile->resources);
    array_destructor(tile->eggs);
    free(tile);
}

void destroy_map(map_t *map)
{
    array_destructor(map->tiles);
    free(map);
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
