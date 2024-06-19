/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

void inventory(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    if (trantorian->param != NULL) {
        sprintf(msg, "ko\n");
        buffer_write(trantorian->client->buffer_answered, msg);
        free(msg);
        free(trantorian->param);
        return;
    }
    sprintf(msg, "[food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d]\n",
        hashmap_get(trantorian->inventory.resources, "food"),
        hashmap_get(trantorian->inventory.resources, "linemate"),
        hashmap_get(trantorian->inventory.resources, "deraumere"),
        hashmap_get(trantorian->inventory.resources, "sibur"),
        hashmap_get(trantorian->inventory.resources, "mendiane"),
        hashmap_get(trantorian->inventory.resources, "phiras"),
        hashmap_get(trantorian->inventory.resources, "thystame"));
    buffer_write(trantorian->client->buffer_answered, msg);
}
