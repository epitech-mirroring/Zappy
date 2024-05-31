/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the eggs
** eggs for the zappy project
*/

#ifndef ZAPPY_EGGS_H
    #define ZAPPY_EGGS_H

    #include "map.h"

/**
 * @struct egg_s
 *
 * This structure represents an egg laid by a Trantorian in the game Zappy.
 * Each egg has a unique ID, coordinates on the map, and belongs to a specific team.
 */
typedef struct egg_s {
    int id;
    coordinates_t coordinates;
    int team;
} egg_t;

#endif //ZAPPY_EGGS_H