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


void look(game_t *game, trantorian_t *trantorian)
{
    char *msg = NULL;

    if (trantorian->direction == NORTH) {
        msg = look_north(game, (short)trantorian->level, trantorian->coordinates);
    } else if (trantorian->direction == EAST) {
        msg = look_east(game, (short)trantorian->level, trantorian->coordinates);
    } else if (trantorian->direction == SOUTH) {
        msg = look_south(game, (short)trantorian->level, trantorian->coordinates);
    } else if (trantorian->direction == WEST) {
        msg = look_west(game, (short)trantorian->level, trantorian->coordinates);
    }

    buffer_write(trantorian->client->buffer_answered, msg);
    free(msg);

}
