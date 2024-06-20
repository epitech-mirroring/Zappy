/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "incantation.h"
#include "actions.h"

static size_t find_trantorian_in_incantation(incantation_t *incantation,
    trantorian_t *trantorian)
{
    size_t i = 0;
    trantorian_t *tmp = NULL;

    for (; i < array_get_size(incantation->trantorians); i++) {
        tmp = array_get_at(incantation->trantorians, i);
        if (uuid_compare(tmp->uuid, trantorian->uuid) == 0)
            break;
    }
    return i;
}

void incantation_dead_trantorian(array_t *incantations,
    trantorian_t *trantorian)
{
    size_t i = 0;
    size_t j = 0;
    incantation_t *incantation = NULL;

    for (; i < array_get_size(incantations); i++) {
        incantation = (incantation_t *)array_get_at(incantations, i);
        j = find_trantorian_in_incantation(incantation, trantorian);
        if (j < array_get_size(incantation->trantorians)) {
            array_remove(incantation->trantorians, j);
            return;
        }
    }
}

static void remove_incantation(game_t *game, array_t *trantorians, size_t i)
{
    trantorian_t *trantorian = NULL;

    for (size_t j = 0; j < array_get_size(trantorians); j++) {
        trantorian = (trantorian_t *)array_get_at(trantorians, j);
        array_remove(trantorian->actions, 0);
        trantorian->incantated = false;
    }
    array_remove(game->incantations, i);
}

void incantations_check(game_t *game)
{
    incantation_t *incantation = NULL;

    for (size_t i = 0; i < array_get_size(game->incantations); i++) {
        incantation = (incantation_t *)array_get_at(game->incantations, i);
        if (incantation->couldown > 0) {
            incantation->couldown--;
            continue;
        }
        if (!can_elevate(game, incantation->trantorians,
            incantation->level, incantation->pos)) {
            remove_incantation(game, incantation->trantorians, i);
        }
    }
}
