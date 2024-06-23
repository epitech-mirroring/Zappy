/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <string.h>
#include "game.h"
#include "actions.h"
#include "ia_actions/look.h"

static void manage_msg(trantorian_t *trantorian, char *tmp, char *msg)
{
    sprintf(tmp, "[%s]\n", msg);
    buffer_write(trantorian->client->buffer_answered, tmp);
    free(msg);
    free(tmp);
}

static hashmap_t *init_tile_content(void)
{
    hashmap_t *resources;

    resources = create_hashmap();
    hashmap_put(resources, "player", 0);
    hashmap_put(resources, "food", 0);
    hashmap_put(resources, "linemate", 0);
    hashmap_put(resources, "deraumere", 0);
    hashmap_put(resources, "sibur", 0);
    hashmap_put(resources, "mendiane", 0);
    hashmap_put(resources, "phiras", 0);
    hashmap_put(resources, "thystame", 0);
    return resources;
}

void look(game_t *game, trantorian_t *trantorian)
{
    char *msg = NULL;
    char *tmp = calloc(100000, sizeof(char));
    hashmap_t *content = init_tile_content();
    coordinates_t coord = trantorian->coordinates;

    if (trantorian->direction == NORTH) {
        msg = look_north(game, (short)trantorian->level, coord, content);
    }
    if (trantorian->direction == EAST) {
        msg = look_east(game, (short)trantorian->level, coord, content);
    }
    if (trantorian->direction == SOUTH) {
        msg = look_south(game, (short)trantorian->level, coord, content);
    }
    if (trantorian->direction == WEST) {
        msg = look_west(game, (short)trantorian->level, coord, content);
    }
    manage_msg(trantorian, tmp, msg);
}
