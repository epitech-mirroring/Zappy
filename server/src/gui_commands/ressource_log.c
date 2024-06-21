/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void pdr_log_gui(game_t *game, trantorian_t *trantorian, char *resource)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pdr %s %s\n", uuid, resource);
    array_push_back(game->gui_log, str);
    free(uuid);
}

void pgt_log_gui(game_t *game, trantorian_t *trantorian, char *resource)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pgt %s %s\n", uuid, resource);
    array_push_back(game->gui_log, str);
    free(uuid);
}
