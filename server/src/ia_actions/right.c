/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

static void turn(trantorian_t *trantorian)
{
    if (trantorian->direction == NORTH) {
        trantorian->direction = EAST;
        return;
    }
    if (trantorian->direction == EAST) {
        trantorian->direction = SOUTH;
        return;
    }
    if (trantorian->direction == SOUTH) {
        trantorian->direction = WEST;
        return;
    }
    if (trantorian->direction == WEST)
        trantorian->direction = NORTH;
}

void right(game_t *game, trantorian_t *trantorian)
{
    char *msg = malloc(sizeof(char) * 100);

    if (trantorian->param != NULL) {
        sprintf(msg, "ko\n");
        buffer_write(trantorian->client->buffer_answered, msg);
        free(msg);
        free(trantorian->param);
        return;
    }
    turn(trantorian);
    sprintf(msg, "ok\n");
    buffer_write(trantorian->client->buffer_answered, msg);
    free(msg);
}
