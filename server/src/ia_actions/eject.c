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

static int eject_north(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.y == 0)
        trantorian->coordinates.y = game->map->height - 1;
    else
        trantorian->coordinates.y--;
    sprintf(msg, "eject: %s\n", get_direction_str(NORTH));
    update_pos(prev, trantorian->coordinates, game->map);
    return 1;
}

static int eject_east(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.x == game->map->width - 1)
        trantorian->coordinates.x = 0;
    else
        trantorian->coordinates.x++;
    sprintf(msg, "eject: %s\n", get_direction_str(EAST));
    update_pos(prev, trantorian->coordinates, game->map);
    return 1;
}

static int eject_south(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.y == game->map->height - 1)
        trantorian->coordinates.y = 0;
    else
        trantorian->coordinates.y++;
    sprintf(msg, "eject: %s\n", get_direction_str(SOUTH));
    update_pos(prev, trantorian->coordinates, game->map);
    return 1;
}

static int eject_west(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.x == 0)
        trantorian->coordinates.x = game->map->width - 1;
    else
        trantorian->coordinates.x--;
    sprintf(msg, "eject: %s\n", get_direction_str(WEST));
    update_pos(prev, trantorian->coordinates, game->map);
    return 1;
}

static int eject_eggs(game_t *game, trantorian_t *trantorian)
{
    egg_t *tmp = NULL;
    size_t i = 0;
    int nb = 0;

    for (i = 0; i < array_get_size(game->eggs);) {
        tmp = (egg_t *)array_get_at(game->eggs, i);
        if (tmp == NULL || tmp->coordinates.x != trantorian->coordinates.x ||
            tmp->coordinates.y != trantorian->coordinates.y) {
                i++;
            continue;
        }
        nb++;
        array_remove(game->eggs, i);
        eject_egg(game, tmp);
        i = 0;
    }
    return nb;
}

void eject_eggs_and_log_client(game_t *game, trantorian_t *trantorian, int nb)
{
    nb += eject_eggs(game, trantorian);
    if (nb > 0) {
        pex_log_gui(game, trantorian);
        buffer_write(trantorian->client->buffer_answered, "ok\n");
    } else {
        buffer_write(trantorian->client->buffer_answered, "ko\n");
    }
}

void eject(game_t *game, trantorian_t *trantorian)
{
    trantorian_t *tmp;
    int nb = 0;

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        tmp = (trantorian_t *)array_get_at(game->trantorians, i);
        if (uuid_compare(tmp->uuid, trantorian->uuid) == 0
            || tmp->coordinates.x != trantorian->coordinates.x ||
            tmp->coordinates.y != trantorian->coordinates.y)
            continue;
        if (trantorian->direction == NORTH)
            nb += eject_north(game, tmp);
        if (trantorian->direction == EAST)
            nb += eject_east(game, tmp);
        if (trantorian->direction == SOUTH)
            nb += eject_south(game, tmp);
        if (trantorian->direction == WEST)
            nb += eject_west(game, tmp);
    }
    eject_eggs_and_log_client(game, trantorian, nb);
}
