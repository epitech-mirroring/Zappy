/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "trantorian.h"
#include "actions.h"

const direction_to_string_t DIRECTION_TO_STRING[] = {
    {NORTH, "NORTH"},
    {EAST, "EAST"},
    {SOUTH, "SOUTH"},
    {WEST, "WEST"},
    {-1, NULL}
};

trantorian_t *init_trantorian(coordinates_t coordinates, client_t *client)
{
    trantorian_t *trantorian = malloc(sizeof(trantorian_t));

    uuid_generate(trantorian->uuid);
    trantorian->coordinates = coordinates;
    trantorian->level = 1;
    trantorian->inventory = init_inventory();
    trantorian->actions = array_constructor(sizeof(action_t), NULL);
    trantorian->direction = NORTH;
    trantorian->waiting_tick = 0;
    trantorian->client = client;
    return trantorian;
}

void destroy_trantorian(trantorian_t *trantorian)
{
    array_destructor(trantorian->actions);
    free(trantorian);
}

void trantorian_tick(trantorian_t *trantorian)
{
    (void)trantorian;
}

char *get_direction_str(enum direction_e direction)
{
    for (int i = 0; DIRECTION_TO_STRING[i].direction != -1; i++) {
        if (DIRECTION_TO_STRING[i].direction == direction)
            return DIRECTION_TO_STRING[i].str;
    }
    return NULL;
}
