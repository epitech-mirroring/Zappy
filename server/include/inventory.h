/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file for inventory
** inventory for Trantorian
*/

#ifndef ZAPPY_INVENTORY_H
    #define ZAPPY_INVENTORY_H

    #include "map.h"

/**
 * @brief Structure of the elements in the inventory
 *
 * This structure represents the elements in the inventory of a Trantorian in the game Zappy.
 * Each element has a type and a quantity.
*/
typedef struct inventory_s {
    int food_time; // need to find accurate variable name
    elements_t elements;
} inventory_t;

#endif //ZAPPY_INVENTORY_H
