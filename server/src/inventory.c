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
    inventory.resources = init_resources();
    return inventory;
}
