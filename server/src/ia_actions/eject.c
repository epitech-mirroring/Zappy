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

static void eject_north(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    if (trantorian->coordinates.y == 0)
        trantorian->coordinates.y = game->map->height - 1;
    else
        trantorian->coordinates.y--;
    sprintf(msg, "eject: %s\n", get_direction_str(NORTH));
}

static void eject_east(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    if (trantorian->coordinates.x == game->map->width - 1)
        trantorian->coordinates.x = 0;
    else
        trantorian->coordinates.x++;
    sprintf(msg, "eject: %s\n", get_direction_str(EAST));
}

static void eject_south(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    if (trantorian->coordinates.y == game->map->height - 1)
        trantorian->coordinates.y = 0;
    else
        trantorian->coordinates.y++;
    sprintf(msg, "eject: %s\n", get_direction_str(SOUTH));
}

static void eject_west(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));

    if (trantorian->coordinates.x == 0)
        trantorian->coordinates.x = game->map->width - 1;
    else
        trantorian->coordinates.x--;
    sprintf(msg, "eject: %s\n", get_direction_str(WEST));
}

static void eject_eggs(game_t *game, trantorian_t *trantorian)
{
    egg_t *tmp = NULL;
    char *msg = calloc(1024, sizeof(char));
    size_t i = 0;

    for (i = 0; i < array_get_size(game->eggs);) {
        tmp = (egg_t *)array_get_at(game->eggs, i);
        if (tmp == NULL || tmp->coordinates.x != trantorian->coordinates.x ||
            tmp->coordinates.y != trantorian->coordinates.y) {
                i++;
            continue;
        }
        array_remove(game->eggs, i);
        eject_egg(game, tmp);
        i = 0;
    }
}

void eject(game_t *game, trantorian_t *trantorian)
{
    trantorian_t *tmp;

    pex_log_gui(game, trantorian);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        tmp = (trantorian_t *)array_get_at(game->trantorians, i);
        if (uuid_compare(tmp->uuid, trantorian->uuid) == 0)
            continue;
        if (tmp->coordinates.x != trantorian->coordinates.x ||
            tmp->coordinates.y != trantorian->coordinates.y)
            continue;
        if (trantorian->direction == NORTH)
            eject_north(game, tmp);
        if (trantorian->direction == EAST)
            eject_east(game, tmp);
        if (trantorian->direction == SOUTH)
            eject_south(game, tmp);
        if (trantorian->direction == WEST)
            eject_west(game, tmp);
    }
    eject_eggs(game, trantorian);
}
