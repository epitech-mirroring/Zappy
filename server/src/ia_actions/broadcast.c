/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "game.h"
#include "actions.h"

static coordinates_t get_closest_player(trantorian_t *sender, trantorian_t *receiver)
{

}

static float get_angle_of_sound(trantorian_t *sender, coordinates_t closest)
{

}

static float get_distance_of_sound(trantorian_t *sender, coordinates_t closest)
{

}


void broadcast(game_t *game, trantorian_t *trantorian)
{
    char *message = malloc(sizeof(char) * 4);

    sprintf(message, "ok\n");
    // todo list all the trantorian test the distance get the angle and the distance (for virtual pos)
    // todo check the trantorian is not the same as the sender
}
