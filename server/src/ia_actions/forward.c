/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

static void forward_north(game_t *game, trantorian_t *trantorian)
{
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.y == 0) {
        trantorian->coordinates.y = game->map->height - 1;
    } else {
        trantorian->coordinates.y -= 1;
    }
    update_pos(prev, trantorian->coordinates, game->map);
}

static void forward_east(game_t *game, trantorian_t *trantorian)
{
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.x == game->map->width - 1) {
        trantorian->coordinates.x = 0;
    } else {
        trantorian->coordinates.x += 1;
    }
    update_pos(prev, trantorian->coordinates, game->map);
}

static void forward_south(game_t *game, trantorian_t *trantorian)
{
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.y == game->map->height - 1) {
        trantorian->coordinates.y = 0;
    } else {
        trantorian->coordinates.y += 1;
    }
    update_pos(prev, trantorian->coordinates, game->map);
}

static void forward_west(game_t *game, trantorian_t *trantorian)
{
    coordinates_t prev = trantorian->coordinates;

    if (trantorian->coordinates.x == 0) {
        trantorian->coordinates.x = game->map->width - 1;
    } else {
        trantorian->coordinates.x -= 1;
    }
    update_pos(prev, trantorian->coordinates, game->map);
}

void forward(game_t *game, trantorian_t *trantorian)
{
    char *msg = malloc(sizeof(char) * 4);

    if (trantorian->direction == NORTH) {
        forward_north(game, trantorian);
    }
    if (trantorian->direction == EAST) {
        forward_east(game, trantorian);
    }
    if (trantorian->direction == SOUTH) {
        forward_south(game, trantorian);
    }
    if (trantorian->direction == WEST) {
        forward_west(game, trantorian);
    }
    sprintf(msg, "ok\n");
    buffer_write(trantorian->client->buffer_answered, msg);
    free(msg);
}
