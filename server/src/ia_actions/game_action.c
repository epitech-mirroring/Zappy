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

static void find_cmd_and_param(char *msg, char *cmd, char *param)
{
    size_t i = 0;

    if (msg == NULL) {
        cmd = NULL;
        param = NULL;
        return;
    }
    for (; msg[i] != ' ' && msg[i] != '\0'; i++) {
        cmd[i] = msg[i];
    }
    if (msg[i] == '\0') {
        param = NULL;
        return;
    }
    i++;
    for (size_t j = 0; msg[i] != '\0'; i++) {
        param[j] = msg[i];
        j++;
    }
}

static void free_all(char *cmd, char *param, char *msg)
{
    free(cmd);
    free(param);
    free(msg);
}

static void gui_log_action_cast(game_t *game,
    action_t *action, trantorian_t *trantorian)
{
    if (strcmp(action->action_name, "Fork") == 0) {
        pfk_log_gui(game, trantorian);
    }
    if (strcmp(action->action_name, "Incantation") == 0) {
        cast_incantation(game, trantorian);
    }
}

static void dup_action(trantorian_t *trantorian,
    size_t i, char *param, game_t *game)
{
    action_t *action = malloc(sizeof(action_t));

    action->action = actions[i].action;
    action->action_name = strdup(actions[i].action_name);
    action->time = actions[i].time;
    array_push_back(trantorian->actions, action);
    if (strlen(param) > 0) {
        trantorian->param = strdup(param);
    } else {
        trantorian->param = NULL;
    }
    gui_log_action_cast(game, action, trantorian);
}

static void find_trantorian_action(game_t *game, trantorian_t *trantorian)
{
    char *msg = buffer_get_next(trantorian->client->buffer_asked, '\n');
    char *cmd = calloc(1024, sizeof(char));
    char *param = calloc(1024, sizeof(char));
    size_t i = 0;

    while (msg != NULL) {
        find_cmd_and_param(msg, cmd, param);
        for (i = 0; actions[i].action != -1 &&
            strcmp(actions[i].action_name, cmd); i++);
        if (array_get_size(trantorian->actions) >= 10 ||
            actions[i].action_name == NULL) {
        } else {
            dup_action(trantorian, i, param, game);
        }
        free(msg);
        msg = buffer_get_next(trantorian->client->buffer_asked, '\n');
    }
    free_all(cmd, param, msg);
}

void find_trantorians_action(game_t *game)
{
    trantorian_t *trantorian = NULL;

    incantations_check(game);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(game->trantorians, i);
        find_trantorian_action(game, trantorian);
    }
}

void check_dead_trantorians(game_t *game)
{
    trantorian_t *trantorian = NULL;
    char *msg = calloc(10, sizeof(char));

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(game->trantorians, i);
        if (trantorian->is_dead) {
            snprintf(msg, 10, "dead\n");
            buffer_write(trantorian->client->buffer_answered, msg);
            pdi_log_gui(game, trantorian);
            trantorian->client->need_to_be_kick = true;
            array_remove(game->trantorians, i);
            incantation_dead_trantorian(game->incantations, trantorian);
            destroy_trantorian(trantorian);
            i--;
        }
    }
    free(msg);
}

bool check_win_team(team_t *team, array_t *trantorians)
{
    size_t nb_for_win = 6;
    trantorian_t *trantorian = NULL;

    for (size_t i = 0; i < array_get_size(trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(trantorians, i);
        if (trantorian->level == 8 && is_in_team(trantorian, team))
            nb_for_win--;
    }
    if (nb_for_win <= 0)
        return true;
    return false;
}

void check_win(game_t *game)
{
    team_t *team = NULL;

    for (size_t i = 0; i < array_get_size(game->teams); i++) {
        team = (team_t *)array_get_at(game->teams, i);
        if (check_win_team(team, game->trantorians)) {
            game->win = true;
            game->winning_team = team->name;
            seg_log_gui(game, team->name);
        }
    }
}
