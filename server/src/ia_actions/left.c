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
        trantorian->direction = WEST;
        return;
    }
    if (trantorian->direction == WEST) {
        trantorian->direction = SOUTH;
        return;
    }
    if (trantorian->direction == SOUTH) {
        trantorian->direction = EAST;
        return;
    }
    if (trantorian->direction == EAST)
        trantorian->direction = NORTH;
}

void left(game_t *game, trantorian_t *trantorian)
{
    char *msg = malloc(sizeof(char) * 100);

    (void)game;
    turn(trantorian);
    sprintf(msg, "ok\n");
    buffer_write(trantorian->client->buffer_answered, msg);
    free(msg);
}
