/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "team.h"

team_t *init_team(char *name)
{
    team_t *team = malloc(sizeof(team_t));

    team->name = name;
    uuid_generate(team->uuid);
    team->trantorians = array_constructor(sizeof(uuid_t), (void *)&uuid_clear);
    return team;
}

void destroy_team(team_t *team)
{
    if (team == NULL)
        return;
    array_destructor(team->trantorians);
    free(team);
}

void add_trantorian_to_team(team_t *team, uuid_t trantorian)
{
    uuid_t trantorian_copy;

    uuid_copy(trantorian_copy, trantorian);
    array_push_back(team->trantorians, &trantorian_copy);
}
