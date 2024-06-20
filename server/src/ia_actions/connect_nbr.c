/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

static bool is_trantorian_in_a_team(team_t *team, trantorian_t *trantorian)
{
    for (size_t i = 0; i < array_get_size(team->trantorians); i++) {
        if (trantorian == array_get_at(team->trantorians, i)) {
            return true;
        }
    }
    return false;
}

void connect_nbr(game_t *game, trantorian_t *trantorian)
{
    char *msg = malloc(sizeof(char) * 100);
    team_t *team = NULL;
    int nb = 0;

    if (trantorian->param != NULL) {
        sprintf(msg, "ko\n");
        buffer_write(trantorian->client->buffer_answered, msg);
        free(msg);
        free(trantorian->param);
        return;
    }
    for (size_t i = 0; array_get_size(game->teams); i++) {
        team = (team_t *)array_get_at(game->teams, i);
        if (is_trantorian_in_a_team(team, trantorian))
            break;
    }
    nb = team->free_places;
    sprintf(msg, "%d\n", nb);
    buffer_write(trantorian->client->buffer_answered, msg);
    free(msg);
}
