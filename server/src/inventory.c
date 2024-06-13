/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "inventory.h"

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
