/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

const direction_to_string_t DIRECTION_TO_STRING[] = {
    {NORTH, "NORTH"},
    {EAST, "EAST"},
    {SOUTH, "SOUTH"},
    {WEST, "WEST"},
    {-1, NULL}
};

static char *get_direction_str(enum direction_e direction)
{
    for (int i = 0; DIRECTION_TO_STRING[i].direction != -1; i++) {
        if (DIRECTION_TO_STRING[i].direction == direction)
            return DIRECTION_TO_STRING[i].str;
    }
    return NULL;
}

char *trantorian_pos_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);
    char *uuid = calloc(37, sizeof(char));
    char *direction = get_direction_str(trantorian->direction);

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "ppo %s %d %d %s\n", uuid, trantorian->coordinates.x,
        trantorian->coordinates.y, direction);
    return str;
}

char *trantorian_level_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "plv %s %d\n", uuid, trantorian->level);
    return str;
}

static char *new_player_connection_log(trantorian_t *trantorian, char *team)
{
    char *str = malloc(sizeof(char) * 100);
    char *uuid = calloc(37, sizeof(char));
    char *direction = get_direction_str(trantorian->direction);

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pnw %s %d %d %s %d %s\n", uuid, trantorian->coordinates.x,
        trantorian->coordinates.y, direction, trantorian->level,
        team);
    return str;
}

void pnw_log_gui(game_t *game, trantorian_t *trantorian, char *team_name)
{
    char *str = new_player_connection_log(trantorian, team_name);

    array_push_back(game->gui_log, str);
}
