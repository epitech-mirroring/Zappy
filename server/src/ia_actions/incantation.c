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
#include "incantation.h"
#include <string.h>

const incantations_check_t incantation_check[] = {
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
}

static void ping_all(game_t *game, array_t *trantorians,
    size_t level, coordinates_t pos)
{
    trantorian_t *tmp = NULL;

    pic_log_gui(game, trantorians, level, pos);
    for (size_t i = 0; i < array_get_size(trantorians); i++) {
        tmp = (trantorian_t *)array_get_at(trantorians, i);
        tmp->incantated = true;
        buffer_write(tmp->client->buffer_answered, "Elevation underway\n");
        update_actions(tmp);
    }
    array_push_back(game->incantations,
        init_incantation(trantorians, pos, level));
}

bool can_elevate(game_t *game, array_t *trantorians, size_t level,
    coordinates_t pos)
{
    incantations_check_t incantation = incantation_check[level - 1];
    tile_t *tile = get_tile_by_coordinates(game->map, pos);

    if (hashmap_get(tile->resources, "linemate") < incantation.linemate ||
        hashmap_get(tile->resources, "deraumere") < incantation.deraumere ||
        hashmap_get(tile->resources, "sibur") < incantation.sibur ||
        hashmap_get(tile->resources, "mendiane") < incantation.mendiane ||
        hashmap_get(tile->resources, "phiras") < incantation.phiras ||
        hashmap_get(tile->resources, "thystame") < incantation.thystame)
        return false;
    if (array_get_size(trantorians) < (size_t)incantation.player)
        return false;
    return true;
}

static void cant_level_up(trantorian_t *trantorian)
{
    trantorian->incantated = false;
    array_remove(trantorian->actions, 0);
    buffer_write(trantorian->client->buffer_answered, "ko\n");
}

static void find_trantorians(game_t *game,
    array_t *trantorians, trantorian_t *trantorian)
{
    action_t *action = NULL;
    trantorian_t *tmp = NULL;

    array_push_back(trantorians, trantorian);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        tmp = (trantorian_t *)array_get_at(game->trantorians, i);
        action = (action_t *)array_get_at(trantorian->actions, 0);
        if (tmp->coordinates.x == trantorian->coordinates.x &&
            tmp->coordinates.y == trantorian->coordinates.y
            && tmp->level == trantorian->level && strcmp(action->action_name,
                "Incantation") != 0 && !tmp->incantated) {
            array_push_back(trantorians, trantorian);
        }
    }
}

void cast_incantation(game_t *game, trantorian_t *trantorian)
{
    array_t *trantorians = array_constructor(sizeof(trantorian_t), NULL);

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        find_trantorians(game, trantorians, trantorian);
    }
    if (can_elevate(game, trantorians,
        trantorian->level, trantorian->coordinates)) {
        ping_all(game, trantorians,
            trantorian->level, trantorian->coordinates);
    } else {
        cant_level_up(trantorian);
    }
}

void incantation(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    if (trantorian->incantated == false) {
        free(msg);
        return;
    }
    trantorian->level++;
    sprintf(msg, "Current level: %ld\n", trantorian->level);
    buffer_write(trantorian->client->buffer_answered, msg);
    sprintf(msg, "pie %ld %ld %ld\n", trantorian->coordinates.x,
        trantorian->coordinates.y, trantorian->level);
    array_push_back(game->gui_log, msg);
    trantorian->incantated = false;
}

incantation_t *init_incantation(array_t *trantorians,
    coordinates_t pos, size_t level)
{
    incantation_t *incantation = malloc((sizeof(incantation_t)));

    incantation->level = level;
    incantation->pos = pos;
    incantation->trantorians = trantorians;
    incantation->trantorians->element_destructor = NULL;
    incantation->couldown = 300;
    return incantation;
}

void destroy_incantation(incantation_t *incantation)
{
    array_destructor(incantation->trantorians);
    free(incantation);
}
