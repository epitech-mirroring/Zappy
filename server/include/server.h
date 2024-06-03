/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_SERVER_H
    #define ZAPPY_SERVER_H

    #include "game.h"
    #include "array.h"

    typedef struct server_s {
        game_t *game;
        array_t *clients;

        size_t single_tick_time;
        size_t prev_tick_time;
        size_t nb_ticks;

        unsigned short port;
    } server_t;

#endif //ZAPPY_SERVER_H
