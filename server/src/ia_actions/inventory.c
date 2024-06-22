/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

static void free_str(char *tmp, char *msg, char *param)
{
    free(tmp);
    free(msg);
    free(param);
}

void inventory(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    char *tmp = calloc(1024, sizeof(char));

    (void)game;
    sprintf(tmp, "[food %d, linemate %d, deraumere %d, sibur %d,",
        hashmap_get(trantorian->inventory.resources, "food"),
        hashmap_get(trantorian->inventory.resources, "linemate"),
        hashmap_get(trantorian->inventory.resources, "deraumere"),
        hashmap_get(trantorian->inventory.resources, "sibur"));
    sprintf(msg, "%s mendiane %d, phiras %d, thystame %d]\n", tmp,
        hashmap_get(trantorian->inventory.resources, "mendiane"),
        hashmap_get(trantorian->inventory.resources, "phiras"),
        hashmap_get(trantorian->inventory.resources, "thystame"));
    buffer_write(trantorian->client->buffer_answered, msg);
    free_str(tmp, msg, trantorian->param);
}
