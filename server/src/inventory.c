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

    inventory.food_time = 0;
    inventory.resources = init_resources();
    return inventory;
}

char *inventory_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);
    inventory_t inventory = trantorian->inventory;

    sprintf(str, "pin %li %i %i %i %i %i %i %i %i %i\n", trantorian->uuid,
    trantorian->coordinates.x, trantorian->coordinates.y,
    hashmap_get(inventory.resources.resources, "food"),
    hashmap_get(inventory.resources.resources, "linemate"),
    hashmap_get(inventory.resources.resources, "deraumere"),
    hashmap_get(inventory.resources.resources, "sibur"),
    hashmap_get(inventory.resources.resources, "mendiane"),
    hashmap_get(inventory.resources.resources, "phiras"),
    hashmap_get(inventory.resources.resources, "thystame"));
    return str;
}
