/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"

void pdi_log_gui(game_t *game, trantorian_t *trantorian, client_t *client)
{
    char *str = calloc(1024, sizeof(char));
    char *uuid = calloc(37, sizeof(char));

    uuid_unparse(trantorian->uuid, uuid);
    sprintf(str, "pdi %s\n", uuid);
    buffer_write(client->buffer_answered, str);
    free(uuid);
}

static bool check_ppo_arg(game_t *game, char *arg)
{
    uuid_t uuid;
    trantorian_t *trantorian = NULL;

    if (uuid_parse(arg, uuid) == -1)
        return false;
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = array_get_at(game->trantorians, i);
        if (uuid_compare(trantorian->uuid, uuid) == 0)
            return true;
    }
    return false;
}

void ppo_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = calloc(1024, sizeof(char));
    uuid_t uuid;
    trantorian_t *trantorian = NULL;

    if (check_ppo_arg(game, arg) == false) {
        sprintf(str, "sbp\n");
        buffer_write(client->buffer_answered, str);
        return;
    }
    uuid_parse(arg, uuid);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = array_get_at(game->trantorians, i);
        if (uuid_compare(trantorian->uuid, uuid) == 0)
            break;
    }
    str = trantorian_pos_to_str(trantorian);
    buffer_write(client->buffer_answered, str);
}

static bool check_plv_arg(game_t *game, char *arg)
{
    uuid_t uuid;
    trantorian_t *trantorian = NULL;

    if (uuid_parse(arg, uuid) == -1)
        return false;
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = array_get_at(game->trantorians, i);
        if (uuid_compare(trantorian->uuid, uuid) == 0)
            return true;
    }
    return false;
}

void plv_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = calloc(1024, sizeof(char));
    uuid_t uuid;
    trantorian_t *trantorian = NULL;

    if (check_plv_arg(game, arg) == false) {
        sprintf(str, "sbp\n");
        buffer_write(client->buffer_answered, str);
        return;
    }
    uuid_parse(arg, uuid);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = array_get_at(game->trantorians, i);
        if (uuid_compare(trantorian->uuid, uuid) == 0)
            break;
    }
    str = trantorian_level_to_str(trantorian);
    buffer_write(client->buffer_answered, str);
}

static bool check_pin_arg(game_t *game, char *arg)
{
    uuid_t uuid;
    trantorian_t *trantorian = NULL;

    if (uuid_parse(arg, uuid) == -1)
        return false;
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = array_get_at(game->trantorians, i);
        if (uuid_compare(trantorian->uuid, uuid) == 0)
            return true;
    }
    return false;
}

void pin_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = calloc(1024, sizeof(char));
    uuid_t uuid;
    trantorian_t *trantorian = NULL;

    if (check_pin_arg(game, arg) == false) {
        sprintf(str, "sbp\n");
        buffer_write(client->buffer_answered, str);
        return;
    }
    uuid_parse(arg, uuid);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = array_get_at(game->trantorians, i);
        if (uuid_compare(trantorian->uuid, uuid) == 0)
            break;
    }
    str = inventory_to_str(trantorian);
    buffer_write(client->buffer_answered, str);
}

void tna_log_gui(game_t *game, char *arg, client_t *client)
{
    char *str = teams_to_string(game->teams);

    buffer_write(client->buffer_answered, str);
}
