/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"
#include <math.h>
#include "ia_actions/broadcast.h"
#include "gui.h"

static signed_coordinates_t v_pos(int pos,
    trantorian_t *receiver, signed_coordinates_t s)
{
    signed_coordinates_t coords = {0, 0};
    int virtual_position[8][2] = {
            {receiver->coordinates.x, receiver->coordinates.y - s.y},
            {receiver->coordinates.x, receiver->coordinates.y + s.y},
            {receiver->coordinates.x - s.x, receiver->coordinates.y},
            {receiver->coordinates.x + s.x, receiver->coordinates.y},
            {receiver->coordinates.x - s.x, receiver->coordinates.y - s.y},
            {receiver->coordinates.x + s.x, receiver->coordinates.y - s.y},
            {receiver->coordinates.x - s.x, receiver->coordinates.y + s.y},
            {receiver->coordinates.x + s.x, receiver->coordinates.y + s.y}
    };

    coords.x = virtual_position[pos][0];
    coords.y = virtual_position[pos][1];
    return coords;
}

static signed_coordinates_t get_closet_coordinates(trantorian_t *sender,
    trantorian_t *receiver, size_t h, size_t w)
{
    int min_distance = 1000000;
    int distance;
    int closest_position[2] = {0, 0};
    signed_coordinates_t size = {w / 2, h / 2};
    signed_coordinates_t coords = {0, 0};

    for (int i = 0; i < 8; i++) {
        distance = sqrt(pow(sender->coordinates.x -
            v_pos(i, receiver, size).x, 2) +
            pow(sender->coordinates.y -
            v_pos(i, receiver, size).y, 2));
        if (distance < min_distance) {
            min_distance = distance;
            closest_position[0] = v_pos(i, receiver, size).x;
            closest_position[1] = v_pos(i, receiver, size).y;
        }
    }
    coords.x = closest_position[0];
    coords.y = closest_position[1];
    return coords;
}

static int get_direction(trantorian_t receiver, trantorian_t *sender,
    signed_coordinates_t closest)
{
    if (receiver.coordinates.x == sender->coordinates.x &&
        receiver.coordinates.y == sender->coordinates.y)
        return NORTH_CENTER;
    if (closest.y > 0 && sender->coordinates.x == receiver.coordinates.x)
        return SOUTH_CENTER;
    if (closest.y < 0 && sender->coordinates.x == receiver.coordinates.x)
        return NORTH_CENTER;
    if (sender->coordinates.y == receiver.coordinates.y && closest.x > 0)
        return WEST_CENTER;
    if (sender->coordinates.y == receiver.coordinates.y && closest.x < 0)
        return EAST_CENTER;
    if (closest.y > 0 && closest.x > 0)
        return SOUTH_WEST;
    if (closest.y > 0 && closest.x < 0)
        return SOUTH_EAST;
    if (closest.y < 0 && closest.x > 0)
        return NORTH_WEST;
    if (closest.y < 0 && closest.x < 0)
        return NORTH_EAST;
    return NORTH_CENTER;
}

static int orientation_correction(int sound_orientation)
{
    if (sound_orientation > 8)
        sound_orientation -= 8;
    if (sound_orientation < 1)
        sound_orientation += 8;
    return sound_orientation;
}

static int sound_orientation(trantorian_t *sender, trantorian_t *receiver,
    size_t height, size_t width)
{
    int orientation = get_direction(*receiver, sender,
        get_closet_coordinates(sender, receiver, height, width));

    if (receiver->direction == NORTH)
        return orientation;
    if (receiver->direction == EAST)
        orientation += 2;
    if (receiver->direction == SOUTH)
        orientation += 4;
    if (receiver->direction == WEST)
        orientation += 6;
    return orientation_correction(orientation);
}

void broadcast(game_t *game, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    char *status_msg = calloc(10, sizeof(char));
    trantorian_t *receiver;
    int orientation;

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        receiver = (trantorian_t *)array_get_at(game->trantorians, i);
        if (receiver->uuid != trantorian->uuid) {
            orientation = sound_orientation(trantorian, receiver,
                game->map->height, game->map->width);
            snprintf(msg, 1024, "message %d, %s\n",
                orientation, trantorian->param);
            buffer_write(receiver->client->buffer_answered, msg);
        }
    }
    free(msg);
    sprintf(status_msg, "ok\n");
    buffer_write(trantorian->client->buffer_answered, status_msg);
    pbc_log_gui(game, trantorian, trantorian->param);
    free(status_msg);
}
