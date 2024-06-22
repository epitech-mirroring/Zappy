/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

char *trantorian_pos_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "ppo %s %d %d %d\n", uuid, trantorian->coordinates.x,
        trantorian->coordinates.y, trantorian->direction + 1);
    free(uuid);
    return str;
}

char *trantorian_level_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "plv %s %d\n", uuid, trantorian->level);
    free(uuid);
    return str;
}

static char *new_player_connection_log_gui(trantorian_t *trantorian,
    char *team)
{
    char *str = malloc(sizeof(char) * 100);
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pnw %s %d %d %i %d %s\n", uuid, trantorian->coordinates.x,
        trantorian->coordinates.y, trantorian->direction + 1,
        trantorian->level, team);
    free(uuid);
    return str;
}

void pnw_log_gui(game_t *game, trantorian_t *trantorian, char *team_name)
{
    char *str = new_player_connection_log_gui(trantorian, team_name);

    array_push_back(game->gui_log, str);
}
