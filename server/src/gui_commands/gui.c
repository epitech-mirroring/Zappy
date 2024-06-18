/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example.
** You can even have multiple lines if you want !
*/

#include "gui.h"
#include "buffer.h"
#include <string.h>

const gui_game_command_t gui_commands[] = {
    {"msz", &msz_log_gui},
    {"bct", &bct_log_gui},
    {"mct", &mct_log_gui},
    {"tna", &tna_log_gui},
    {"ppo", &ppo_log_gui},
    {"plv", &plv_log_gui},
    {"pin", &pin_log_gui},
    {NULL, NULL}
};

const gui_server_command_t gui_commands2[] = {
    {"sgt", &sgt_log_gui},
    {"sst", &sst_log_gui},
    {NULL, NULL}
};

static void update_graphic_client_buffer(array_t *clients, char *msg)
{
    client_t *client = NULL;

    for (size_t i = 0; i < array_get_size(clients); i++) {
        client = (client_t *)array_get_at(clients, i);
        if (client->type == GRAPHIC) {
            buffer_write(client->buffer_answered, msg);
        }
    }
}

void update_graphic_clients_buffer(server_t *server)
{
    char *msg = NULL;

    for (size_t i = 0; i < array_get_size(server->game->gui_log); i++) {
        msg = (char *)array_get_at(server->game->gui_log, i);
        update_graphic_client_buffer(server->clients, msg);
    }
    array_clear(server->game->gui_log);
}

static char *cut_str(char * str, int start)
{
    char *new_str;
    int i = 0;

    if (str == NULL)
        return NULL;
    if (start < 0)
        return NULL;
    if (start >= strlen(str))
        return NULL;
    new_str = malloc(sizeof(char) * (strlen(str) - start + 1));
    for (i = 0; str[start] != '\0' && str[start] != '\n'; i++) {
        new_str[i] = str[start];
        start++;
    }
    new_str[i] = '\0';
    return new_str;

}

static void run_gui_command(server_t *server, client_t *client, char *msg)
{
    char *cmd = strtok(msg, " \n");
    char *arg = cut_str(msg, strlen(cmd) + 1);

    for (size_t i = 0; gui_commands[i].cmd != NULL; i++) {
        if (strcmp(gui_commands[i].cmd, cmd) == 0) {
            gui_commands[i].func(server->game, arg);
            free(arg);
            return;
        }
    }
    for (size_t i = 0; gui_commands2[i].cmd != NULL; i++) {
        if (strcmp(gui_commands2[i].cmd, cmd) == 0) {
            gui_commands2[i].func(server, arg);
            free(arg);
            return;
        }
    }
    free(arg);
    suc_log_gui(server->game);
}

void run_gui_commands(server_t *server)
{
    client_t *client = NULL;
    char *msg = NULL;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (client->type != GRAPHIC)
            continue;
        for (msg = buffer_get_next(client->buffer_asked); msg != NULL;
            msg = buffer_get_next(client->buffer_asked)) {
            run_gui_command(server, client, msg);
        }
    }
}

void new_client_unknow_team(game_t *game, client_t *client,
    char *msg, size_t index)
{
    if (strcmp(msg, "GRAPHIC") == 0) {
        client->type = GRAPHIC;
        array_push_back(game->gui_clients, client);
        array_remove(game->clients_without_team, index);
        return;
    }
    buffer_write(client->buffer_answered, "ko\n");
}
