/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the eggs
** eggs for the zappy project
*/

#ifndef ZAPPY_EGGS_H
    #define ZAPPY_EGGS_H

/**
 * @struct s_egg
 *
 * This structure represents an egg laid by a Trantorian in the game Zappy.
 * Each egg has a unique ID, coordinates on the map, and belongs to a specific team.
 */
typedef struct s_egg {
    int id;
    t_coordinates coordinates;
    int team;
} t_egg;

#endif //ZAPPY_EGGS_H