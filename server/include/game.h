/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_GAME_H
    #define ZAPPY_GAME_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus
    #include "array.h"
    #include "map.h"
    #include "trantorian.h"
    #include "egg.h"

    /**
     * @struct game_s
     *
     * This structure represents a game in the game Zappy.
     * Each game has an array of teams, an array of eggs, an array
     * of Trantorians, and a map.
     *
     */
    typedef struct game_s {
        array_t *teams;
        array_t *eggs; //array of pointers to eggs stored in the map
        array_t *trantorians;

        map_t *map;
    } game_t;

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif //ZAPPY_GAME_H
