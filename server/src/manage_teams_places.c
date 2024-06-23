/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "uuid/uuid.h"

static void fill_team_egg(game_t *game, team_t *team, size_t nb)
{
    for (size_t i = 0; i < game->min_places - nb; i++) {
        array_push_back(game->eggs, generate_egg(team->uuid, game->map));
    }
}

void manage_teams_places(game_t *game)
{
    team_t *team = NULL;
    int nb_in_teams = 0;

    for (size_t i = 0; i < array_get_size(game->teams); i++) {
        team = (team_t *)array_get_at(game->teams, i);
        nb_in_teams = array_get_size(team->trantorians);
        if (team->free_places + nb_in_teams < game->min_places) {
            fill_team_egg(game, team, team->free_places);
            team->free_places = game->min_places;
        }
    }
}

static int is_trantorian_in_team(trantorian_t *trantorian, team_t *team)
{
    uuid_t uuid;

    for (size_t i = 0; i < array_get_size(team->trantorians); i++) {
        uuid_copy(uuid,
            ((trantorian_t *)array_get_at(team->trantorians, i))->uuid);
        if (uuid_compare(uuid, trantorian->uuid) == 0)
            return (int)i;
    }
    return -1;
}

void remove_dead_trantorian(trantorian_t *trantorian, array_t *teams)
{
    size_t size = array_get_size(teams);
    team_t *team = NULL;
    int j = 0;

    for (size_t i = 0; i < size; i++) {
        team = (team_t *)array_get_at(teams, i);
        j = is_trantorian_in_team(trantorian, team);
        if (j != -1) {
            break;
        }
    }
    array_remove(team->trantorians, j);
    destroy_trantorian(trantorian);
}
