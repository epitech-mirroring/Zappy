/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server.h"

void sgt_log_gui(server_t *server)
{
    char *str = calloc(1024, sizeof(char));
    int freq = 1000000 / server->single_tick_time;

    sprintf(str, "sgt %d\n", freq);
    array_push_back(server->game->gui_log, str);
    free(str);
}

void sst_log_gui(server_t *server, char *arg)
{
    char *str = calloc(1024, sizeof(char));
    int freq = atoi(arg);

    if (freq < 1) {
        sprintf(str, "sbp\n");
        array_push_back(server->game->gui_log, str);
        free(str);
        return;
    }
    server->single_tick_time = 1000000 / freq;
    sprintf(str, "sst %d\n", freq);
    array_push_back(server->game->gui_log, str);
    free(str);
}
