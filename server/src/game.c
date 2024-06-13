/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <stdio.h>
#include <string.h>
#include "client.h"
#include "buffer.h"
#include "game.h"
#include "array.h"
#include "team.h"
#include "trantorian.h"

game_t *init_game(char *teams, size_t map_size[2], size_t team_max_size)
{
    game_t *game = malloc(sizeof(game_t));

    game->teams = array_constructor(sizeof(team_t), NULL);
    for (size_t i = 0; i < strlen(teams); i++) {
        array_push_back(game->teams, init_team(teams[i]));
    }
    game->eggs = NULL;
    game->trantorians = array_constructor(sizeof(trantorian_t), NULL);
    game->team_max_size = team_max_size;
    game->map =  NULL; //TODO: create map
    return game;
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

    for (size_t i = 0; i < array_get_size(teams); i++) {
        team = (team_t *)array_get_at(teams, i);
        if (strcmp(team->name, team_name) == 0)
            return team;
    }
    return NULL;
}


void create_trantorians(game_t *game, team_t *team)
{
    // trantorian_t *trantorian = init_trantorian(team);
    trantorian_t *trantorian = NULL;

    if (trantorian == NULL)
        return;
    // add_trantorian(game, trantorian);
}

bool can_create_trantorian(game_t *game, char *team_name)
{
    team_t *team = get_team_by_name(game->teams, team_name);

    if (team == NULL)
        return false;
    if (array_get_size(team->trantorians) >= game->team_max_size)
        return false;
    return true;
}
