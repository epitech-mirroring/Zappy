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
    inventory.resources.food_count = 10;
    inventory.resources.linemate_count = 0;
    inventory.resources.deraumere_count = 0;
    inventory.resources.sibur_count = 0;
    inventory.resources.mendiane_count = 0;
    inventory.resources.phiras_count = 0;
    inventory.resources.thystame_count = 0;
    return inventory;
}

char *inventory_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);
    inventory_t inventory = trantorian->inventory;

    sprintf(str, "pin %li %i %i %i %i %i %i %i %i %i\n", trantorian->uuid,
    trantorian->coordinates.x, trantorian->coordinates.y,
    inventory.resources.food_count, inventory.resources.linemate_count,
    inventory.resources.deraumere_count, inventory.resources.sibur_count,
    inventory.resources.mendiane_count, inventory.resources.phiras_count,
    inventory.resources.thystame_count);
    return str;
}
