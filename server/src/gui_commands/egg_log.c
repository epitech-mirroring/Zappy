/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void pfk_log_gui(game_t *game, trantorian_t *trantorian)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = NULL;

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pfk #%s\n", uuid);
    array_push_back(game->gui_log, str);
    free(str);
}

void enw_log_gui(game_t *game, egg_t *egg, trantorian_t *trantorian)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid_egg = NULL;
    char *uuid_player = NULL;

    uuid_unparse(egg->uuid, uuid_egg);
    uuid_unparse(trantorian->uuid, uuid_player);
    sprintf(str, "enw #%s #%s %d %d\n", uuid_egg, uuid_player,
        egg->coordinates.x, egg->coordinates.y);
    array_push_back(game->gui_log, str);
    free(str);
}

void ebo_log_gui(game_t *game, egg_t *egg)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = NULL;

    uuid_unparse(egg->uuid, uuid);
    sprintf(str, "ebo #%s\n", uuid);
    array_push_back(game->gui_log, str);
    free(str);
}

void edi_log_gui(game_t *game, egg_t *egg)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = NULL;

    uuid_unparse(egg->uuid, uuid);
    sprintf(str, "edi #%s\n", uuid);
    array_push_back(game->gui_log, str);
    free(str);
}
