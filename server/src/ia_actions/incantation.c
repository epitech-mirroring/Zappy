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

const incantation_check_t incantation_check[] = {
    {1, 1, 1, 0, 0, 0, 0, 0},
    {2, 2, 1, 1, 1, 0, 0, 0},
    {3, 2, 2, 0, 1, 0, 2, 0},
    {4, 4, 1, 1, 2, 0, 1, 0},
    {5, 4, 1, 2, 1, 3, 0, 0},
    {6, 6, 1, 2, 3, 0, 1, 0},
    {7, 6, 2, 2, 2, 2, 2, 1},
    {-1, -1, -1, -1, -1, -1, -1, -1}
};

static void update_actions(trantorian_t *trantorian)
{
    action_t *action = malloc(sizeof(action_t));
    action_t *tmp = NULL;

    action->action = INCANTATION;
    action->time = 300;
    action->action_name = strdup("Incantation");
    tmp = (action_t *)array_get_at(trantorian->actions, 0);
    if (tmp != NULL)
        tmp->time = trantorian->waiting_tick;
    array_insert(trantorian->actions, action, 0);
    trantorian->waiting_tick = action->time;
}

static void ping_all(game_t *game, array_t *trantorians,
    size_t level, coordinates_t pos)
{
    trantorian_t *tmp = NULL;
    char *msg = calloc(100 * array_get_size(trantorians), sizeof(char));

    pic_log_gui(game, trantorians, level, pos);
    for (size_t i = 0; i < array_get_size(trantorians); i++) {
        tmp = (trantorian_t *)array_get_at(trantorians, i);
        buffer_write(tmp->client->buffer_answered, "Elevation underway\n");
        update_actions(tmp);
    }
}

static bool can_elevate(game_t *game, array_t *trantorians, size_t level,
    coordinates_t pos)
{
    incantation_check_t incantation = incantation_check[level - 1];
    tile_t *tile = get_tile_by_coordinates(game->map, pos);
    size_t i = 0;

    if (hashmap_get(tile->resources, "linemate") < incantation.linemate ||
        hashmap_get(tile->resources, "deraumere") < incantation.deraumere ||
        hashmap_get(tile->resources, "sibur") < incantation.sibur ||
        hashmap_get(tile->resources, "mendiane") < incantation.mendiane ||
        hashmap_get(tile->resources, "phiras") < incantation.phiras ||
        hashmap_get(tile->resources, "thystame") < incantation.thystame)
        return false;
    if (array_get_size(trantorians) < incantation.player)
        return false;
    return true;
}

void cast_incantation(game_t *game, trantorian_t *trantorian)
{
    trantorian_t *tmp = trantorian;
    array_t *trantorians = array_constructor(sizeof(trantorian_t), NULL);
    action_t *action = (action_t *)array_get_at(trantorian->actions, 0);

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        tmp = (trantorian_t *)array_get_at(game->trantorians, i);
        if (tmp->coordinates.x == trantorian->coordinates.x &&
            tmp->coordinates.y == trantorian->coordinates.y
            && tmp->level == trantorian->level && strcmp(action->action_name,
                "Incantation") != 0) {
            array_push_back(trantorians, trantorian);
        }
    }
    if (can_elevate(game, trantorians,
        trantorian->level, trantorian->coordinates)) {
        ping_all(game, trantorians,
            trantorian->level, trantorian->coordinates);
    } else {
        buffer_write(trantorian->client->buffer_answered, "ko\n");
    }
}

void incantation(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    sprintf(msg, "Current level: %ld\n", trantorian->level);
    buffer_write(trantorian->client->buffer_answered, msg);
    sprintf(msg, "pie %ld %ld %ld\n", trantorian->coordinates.x,
        trantorian->coordinates.y, trantorian->level);
    array_push_back(game->gui_log, msg);
}
