/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void seg_log_gui(game_t *game, char *team_name)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "seg %s\n", team_name);
    array_push_back(game->gui_log, str);
}

void smg_log_gui(game_t *game, char *msg)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "smg %s\n", msg);
    array_push_back(game->gui_log, str);
}

void suc_log_gui(game_t *game)
{
    char *str = calloc(1024, sizeof(char));

    sprintf(str, "suc\n");
    array_push_back(game->gui_log, str);
}
