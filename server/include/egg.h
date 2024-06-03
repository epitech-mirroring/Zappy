/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the eggs
** eggs for the zappy project
*/

#ifndef ZAPPY_EGG_H
    #define ZAPPY_EGG_H

    #include "map.h"
    #include "uuid/uuid.h"

    /**
     * @struct egg_s
     *
     * This structure represents an egg laid by a Trantorian in the game Zappy.
     * Each egg has a unique ID, coordinates on the map, and belongs to a specific team.
     */
    typedef struct egg_s {
        uuid_t team_uuid;
        coordinates_t coordinates;
    } egg_t;

#endif //ZAPPY_EGG_H