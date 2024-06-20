/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void pic_log_gui(game_t *game, array_t *trantorians,
    size_t level, coordinates_t pos)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = calloc(37, sizeof(char));
    trantorian_t *trantorian = NULL;

    sprintf(str, "pic %lu %lu %lu %s\n", pos.x, pos.y, level);
    for (size_t i = 0; i < array_get_size(trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(trantorians, i);
        uuid_unparse(trantorian->uuid, uuid);
        sprintf(str, "%s %s", str, uuid);
    }
    sprintf(str, "%s\n", str);
    array_push_back(game->gui_log, str);
    free(uuid);
}
