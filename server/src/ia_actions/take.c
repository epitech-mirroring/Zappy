/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

static bool check_take_cmd(game_t *game, char *param, tile_t *tile)
{
    if (param == NULL) {
        return false;
    }
    if (tile == NULL) {
        return false;
    }
    if (hashmap_get(tile->resources, param) == 0) {
        return false;
    }
    return true;
}

void take(game_t *game, trantorian_t *trantorian)
{
    char *msg = malloc(sizeof(char) * 100);
    coordinates_t coords = trantorian->coordinates;
    tile_t *tile = get_tile_by_coordinates(game->map, coords);

    if (!check_take_cmd(game, trantorian->param, tile)) {
        sprintf(msg, "ko\n");
        buffer_write(trantorian->client->buffer_answered, msg);
        free(msg);
        return;
    }
    hashmap_set(tile->resources, trantorian->param,
        hashmap_get(tile->resources, trantorian->param) - 1);
    hashmap_set(trantorian->inventory.resources, trantorian->param,
        hashmap_get(trantorian->inventory.resources, trantorian->param) + 1);
    sprintf(msg, "ok\n");
    buffer_write(trantorian->client->buffer_answered, msg);
    free(msg);
    free(trantorian->param);
}
