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

static bool is_trantorian_in_team(team_t *team, trantorian_t *trantorian)
{
    trantorian_t *tmp = NULL;

    for (size_t i = 0; i < array_get_size(team->trantorians); i++) {
        tmp = array_get_at(team->trantorians, i);
        if (uuid_compare(tmp->uuid, trantorian->uuid) == 0)
            return true;
    }
    return false;
}

void fork_ia(game_t *game, trantorian_t *trantorian)
{
    egg_t *egg = NULL;
    team_t *team = NULL;

    if (trantorian->is_dead)
        return;
    for (size_t i = 0; i < array_get_size(game->teams); i++) {
        team = array_get_at(game->teams, i);
        if (is_trantorian_in_team(team, trantorian)) {
            break;
        }
    }
    egg = init_egg(team->uuid, trantorian->coordinates);
    array_push_back(game->eggs, egg);
    enw_log_gui(game, egg, trantorian);
    buffer_write(trantorian->client->buffer_answered, "ok\n");
}
