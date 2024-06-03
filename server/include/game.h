/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_GAME_H
    #define ZAPPY_GAME_H

    #include "array.h"
    #include "map.h"
    #include "trantorian.h"
    #include "egg.h"

    typedef struct game_s {
        array_t *teams;
        array_t *eggs;
        array_t *trantorians;

        map_t *map;
    } game_t;

#endif //ZAPPY_GAME_H
