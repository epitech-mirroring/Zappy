/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <string.h>
#include "game.h"
#include "actions.h"

#ifndef IA_BROADCAST_H
    #define IA_BROADCAST_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    enum orientation_e {
        NORTH_CENTER = 1,
        NORTH_EAST = 2,
        NORTH_WEST = 3,
        SOUTH_CENTER = 4,
        SOUTH_EAST = 5,
        SOUTH_WEST = 6,
        EAST_CENTER = 7,
        WEST_CENTER = 8
    };

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif // IA_BROADCAST_H
