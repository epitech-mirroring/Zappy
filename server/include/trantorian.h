/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_TRANTORIAN_H
#define ZAPPY_TRANTORIAN_H

#include <stdio.h>
#include "inventory.h"

/**
 * @struct s_coordinates
 *
 * This structure represents the coordinates of a tile on the map.
 * Each tile has an x and y coordinate.
 */
enum e_direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

/**
 * @struct s_trantorian
 *
 * this structure represents a trantorian in the game Zappy
 * Each trantorian has a unique ID, coordinates on the map, a level, an inventory, an action list, a direction, and a team.
 */
typedef struct s_trantorian {
    int id;
    t_coordinates coordinates;
    int level;
    t_inventory inventory;
    t_action_list *action_list;
    enum e_direction direction;
    int team;
} t_trantorian;

#endif //ZAPPY_TRANTORIAN_H
