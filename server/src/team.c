/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "team.h"
#include <string.h>

team_t *init_team(char *name)
{
    team_t *team = malloc(sizeof(team_t));

    team->name = name;
    uuid_generate(team->uuid);
    team->trantorians = array_constructor(sizeof(uuid_t), NULL);
    return team;
}

void destroy_team(team_t *team)
{
    if (team != NULL) {
        array_destructor(team->trantorians);
        uuid_clear(team->uuid);
    }
    free(team);
}

void add_trantorian_to_team(team_t *team, uuid_t trantorian)
{
    uuid_t trantorian_copy;

    uuid_copy(trantorian_copy, trantorian);
    array_push_back(team->trantorians, &trantorian_copy);
}

static char *team_to_string(team_t *team)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "tna %s\n", team->name);
    return str;
}

char *teams_to_string(array_t *teams)
{
    char *str = calloc(1024 * array_get_size(teams), sizeof(char));
    char *tmp = NULL;
    char *prev = NULL;
    team_t *team = NULL;

    for (size_t i = 0; i < array_get_size(teams); i++) {
        team = (team_t *)array_get_at(teams, i);
        tmp = team_to_string(team);
        prev = strdup(str);
        sprintf(str, "%s%s", prev, tmp);
        free(tmp);
        free(prev);
    }
    return str;
}

bool is_in_team(trantorian_t *trantorian, team_t *team)
{
    uuid_t trantorian_copy;

    for (size_t i = 0; i < array_get_size(team->trantorians); i++) {
        uuid_copy(trantorian_copy,
            *(uuid_t *)array_get_at(team->trantorians, i));
        if (uuid_compare(trantorian->uuid, trantorian_copy) == 0)
            return true;
    }
    return false;
}
