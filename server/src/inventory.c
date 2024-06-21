/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "inventory.h"
#include "trantorian.h"

inventory_t init_inventory(void)
{
    inventory_t inventory;

    inventory.food_time = 126;
    inventory.resources = init_resources();
    return inventory;
}

char *inventory_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 1024);
    inventory_t inventory = trantorian->inventory;

    sprintf(str, "pin %li %i %i %i %i %i %i %i %i %i\n", trantorian->uuid,
    trantorian->coordinates.x, trantorian->coordinates.y,
    hashmap_get(inventory.resources, "food"),
    hashmap_get(inventory.resources, "linemate"),
    hashmap_get(inventory.resources, "deraumere"),
    hashmap_get(inventory.resources, "sibur"),
    hashmap_get(inventory.resources, "mendiane"),
    hashmap_get(inventory.resources, "phiras"),
    hashmap_get(inventory.resources, "thystame"));
    return str;
}
