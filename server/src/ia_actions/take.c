/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"
#include "gui.h"

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

static char *find_resource_number(char *param)
{
    if (strcmp(param, "food") == 0)
        return "q0";
    if (strcmp(param, "linemate") == 0)
        return "q1";
    if (strcmp(param, "deraumere") == 0)
        return "q2";
    if (strcmp(param, "sibur") == 0)
        return "q3";
    if (strcmp(param, "mendiane") == 0)
        return "q4";
    if (strcmp(param, "phiras") == 0)
        return "q5";
    return "q6";
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
    pgt_log_gui(game, trantorian, find_resource_number(trantorian->param));
}
