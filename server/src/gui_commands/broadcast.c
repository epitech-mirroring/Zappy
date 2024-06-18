/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void pbc_log_gui(game_t *game, trantorian_t *trantorian, char *msg)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = NULL;

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pbc %s %s\n", uuid, msg);
    array_push_back(game->gui_log, str);
}

void pex_log_gui(game_t *game, trantorian_t *trantorian)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = NULL;

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pex %s\n", uuid);
    array_push_back(game->gui_log, str);
}
