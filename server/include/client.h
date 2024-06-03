/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_CLIENT_H
    #define ZAPPY_CLIENT_H

    #include "array.h"
    #include <uuid/uuid.h>

    typedef enum client_type_e {
        AI = 0,
        GRAPHIC = 1,
    } client_type_t;

    typedef struct client_s {
        int socket;
        client_type_t type;

        array_t *queue_asked;
        array_t *queue_answered;

        uuid_t uuid;
        size_t last_tick_action;
    } client_t;

#endif //ZAPPY_CLIENT_H
