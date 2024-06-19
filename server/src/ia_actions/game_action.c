/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"
#include "gui.h"
#include <string.h>

const action_t actions[] = {
    {FORWARD, 7, "Forward"},
    {RIGHT, 7, "Right"},
    {LEFT, 7, "Left"},
    {LOOK, 7, "Look"},
    {INVENTORY, 1, "Inventory"},
    {BROADCAST, 7, "Broadcast"},
    {CONNECT_NBR, 0, "Connect_nbr"},
    {FORK, 42, "Fork"},
    {EJECT, 7, "Eject"},
    {TAKE, 7, "Take"},
    {SET, 7, "Set"},
    {INCANTATION, 300, "Incantation"},
    {-1, -1, NULL}
};

static action_t *dup_action(size_t i)
{
    action_t *action = malloc(sizeof(action_t));

    action->action = actions[i].action;
    action->action_name = strdup(actions[i].action_name);
    action->time = actions[i].time;
    return action;
}

static void find_trantorian_action(game_t *game, trantorian_t *trantorian)
{
    char *msg = buffer_get_next(trantorian->client->buffer_asked);
    size_t i = 0;
    action_t *action = NULL;

    while (msg != NULL) {
        for (i = 0; actions[i].action != -1 &&
            strcmp(actions[i].action_name, msg); i++);
        if (array_get_size(trantorian->actions) >= 10 ||
            actions[i].action_name == NULL) {
            buffer_write(trantorian->client->buffer_answered, "ko\n");
        } else {
            action = dup_action(i);
            array_push_back(trantorian->actions, action);
        }
        msg = buffer_get_next(trantorian->client->buffer_asked);
    }
}

void find_trantorians_action(game_t *game)
{
    trantorian_t *trantorian = NULL;

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(game->trantorians, i);
        find_trantorian_action(game, trantorian);
    }
}

void check_dead_trantorians(game_t *game)
{
    trantorian_t *trantorian = NULL;
    char *msg = malloc(sizeof(char) * 5);

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(game->trantorians, i);
        if (trantorian->is_dead) {
            sprintf(msg, "dead\n");
            buffer_write(trantorian->client->buffer_answered, msg);
            pdi_log_gui(game, trantorian);
            trantorian->client->useless = true;
            array_remove(game->trantorians, i);
            i--;
        }
    }
    free(msg);
}
