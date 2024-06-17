/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "trantorian.h"
#include "actions.h"

trantorian_t *init_trantorian(coordinates_t coordinates, client_t *client)
{
    trantorian_t *trantorian = malloc(sizeof(trantorian_t));

    uuid_generate(trantorian->uuid);
    trantorian->coordinates = coordinates;
    trantorian->level = 1;
    trantorian->inventory = init_inventory();
    trantorian->actions = array_constructor(1, NULL);
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
