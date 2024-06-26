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

static char *cut_str(char *str, int start)
{
    char *new_str;
    int i = 0;

    if (str == NULL)
        return NULL;
    if (start < 0)
        return NULL;
    if (start >= (int)strlen(str))
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
    char *arg = cut_str(msg, 4);
    char *cmd = strtok(msg, " \n");

    for (size_t i = 0; gui_commands[i].cmd != NULL; i++) {
        if (strcmp(gui_commands[i].cmd, cmd) == 0) {
            gui_commands[i].func(server->game, arg, client);
            free(arg);
            return;
        }
    }
    for (size_t i = 0; gui_commands2[i].cmd != NULL; i++) {
        if (strcmp(gui_commands2[i].cmd, cmd) == 0) {
            gui_commands2[i].func(server, arg, client);
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
        for (msg = buffer_get_next(client->buffer_asked, '\n'); msg != NULL;
            msg = buffer_get_next(client->buffer_asked, '\n')) {
            run_gui_command(server, client, msg);
        }
        free(msg);
    }
    gui_send_updates(server->game, server);
}

void new_client_unknow_team(game_t *game, client_t *client,
    char *msg, size_t index)
{
    if (strcmp(msg, "GRAPHIC") == 0) {
        client->type = GRAPHIC;
        array_push_back(game->gui_clients, client);
    } else {
        client->need_to_be_kick = true;
    }
    array_remove(game->clients_without_team, index);
}

void gui_send_updates(game_t *game, server_t *server)
{
    trantorian_t *trantorian = NULL;
    client_t *client = NULL;
    size_t nb_clients = array_get_size(server->clients);
    size_t nb_ia = array_get_size(game->trantorians);
    char *uuid = calloc(37, sizeof(char));

    for (size_t i = 0; i < nb_clients; i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (client->type != GRAPHIC)
            continue;
        for (size_t j = 0; j < nb_ia; j++) {
            trantorian = (trantorian_t *)array_get_at(game->trantorians, j);
            uuid_unparse(trantorian->uuid, uuid);
            ppo_log_gui(game, uuid, client);
            plv_log_gui(game, uuid, client);
            pin_log_gui(game, uuid, client);
        }
    }
    free(uuid);
}
