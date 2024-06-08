/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <stdio.h>
#include "client.h"
#include "buffer.h"
#include "game.h"
#include "array.h"
#include "team.h"
#include "trantorian.h"

game_t *init_game(array_t *teams, size_t map_size[2], size_t team_max_size)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (NULL);
    game->teams = teams;
    game->eggs = NULL;
    game->trantorians = array_constructor(sizeof(trantorian_t), NULL);
    game->map =  NULL; //TODO: create map
    return (game);
}

void destroy_game(game_t *game)
{
    if (game == NULL)
        return;
    array_destructor(game->teams);
    array_destructor(game->eggs);
    array_destructor(game->trantorians);
    //map_destroy(game->map); TODO
    free(game);
}

void game_tick(game_t *game)
{
    //TODO
}

static team_t *get_team_by_name(array_t *teams, char *team_name)
{
    team_t *team = NULL;

    for (size_t i = 0; i < teams->size; i++) {
        team = array_get_elem_at(teams, i);
        if (strcmp(team->name, team_name) == 0)
            return (team);
    }
    return (NULL);
}


void create_trantorians(game_t *game, team_t *team)
{
    trantorian_t *trantorian = init_trantorian(team);

    if (trantorian == NULL)
        return;
    add_trantorian(game, trantorian);
}
