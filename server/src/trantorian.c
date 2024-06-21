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
    hashmap_set(trantorian->inventory.resources, "food", 10);
    trantorian->actions = array_constructor(sizeof(action_t), NULL);
    trantorian->direction = NORTH;
    trantorian->waiting_tick = 0;
    trantorian->client = client;
    trantorian->nb_waiting_actions = 0;
    trantorian->is_dead = false;
    trantorian->incantated = false;
    trantorian->param = NULL;
    return trantorian;
}

void destroy_trantorian(trantorian_t *trantorian)
{
    if (trantorian != NULL) {
        array_destructor(trantorian->actions);
        destroy_hashmap(trantorian->inventory.resources);
        uuid_clear(trantorian->uuid);
    }
    free(trantorian);
}

void trantorian_tick(trantorian_t *trantorian)
{
    int nb_food = hashmap_get(trantorian->inventory.resources, "food");

    if (trantorian->is_dead)
        return;
    if (trantorian->waiting_tick > 0)
        trantorian->waiting_tick--;
    if (trantorian->inventory.food_time == 0) {
        if (nb_food == 0) {
            trantorian->is_dead = true;
            return;
        } else {
            trantorian->inventory.food_time = 126;
            hashmap_set(trantorian->inventory.resources, "food", nb_food - 1);
        }
    }
    trantorian->inventory.food_time--;
}

char *get_direction_str(enum direction_e direction)
{
    for (int i = 0; DIRECTION_TO_STRING[i].direction != -1; i++) {
        if (DIRECTION_TO_STRING[i].direction == direction)
            return DIRECTION_TO_STRING[i].str;
    }
    return NULL;
}
