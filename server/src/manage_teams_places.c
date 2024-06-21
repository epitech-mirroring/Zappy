/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

static size_t get_nb_eggs_in_team(uuid_t team_uuid, array_t *eggs)
{
    size_t nb = 0;
    egg_t *egg = NULL;

    for (size_t i = 0; i < array_get_size(eggs); i++) {
        egg = (egg_t *)array_get_at(eggs, i);
        if (uuid_compare(egg->team_uuid, team_uuid) == 0)
            nb++;
    }
    return nb;
}

static void fill_team_egg(game_t *game, team_t *team, size_t nb)
{
    for (size_t i = 0; i < game->min_places - nb; i++) {
        array_push_back(game->eggs, generate_egg(team->uuid, game->map));
    }
}

void manage_teams_places(game_t *game)
{
    team_t *team = NULL;
    size_t nb = 0;

    for (size_t i = 0; i < array_get_size(game->teams); i++) {
        team = (team_t *)array_get_at(game->teams, i);
        nb = array_get_size(team->trantorians) +
            get_nb_eggs_in_team(team->uuid, game->eggs);
        if (nb < game->min_places) {
                fill_team_egg(game, team, nb);
            }
    }
}
