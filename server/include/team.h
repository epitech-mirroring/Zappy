/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** team include file for the trantorian
** team for the trantorian
*/

#ifndef ZAPPY_TEAM_H
    #define ZAPPY_TEAM_H

    #include "trantorian.h"
    #include "array.h"

/**
 * @struct team_s
 *
 * This structure represents a team in the game Zappy.
 * Each team has a unique ID, a name, a number of members, and an array of Trantorians.
 */
typedef struct team_s {
    uuid_t uuid;
    array_t *trantorians;
    char *name;
} team_t;

#endif //ZAPPY_TEAM_H
