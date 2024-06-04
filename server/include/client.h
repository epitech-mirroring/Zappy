/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_CLIENT_H
    #define ZAPPY_CLIENT_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    #include "array.h"
    #include <uuid/uuid.h>

/**
 * @enum client_type_e
 *
 * This enumeration represents the type of a client in the game Zappy.
 * Each client can be an AI or a graphic client.
 */
typedef enum client_type_e {
    AI = 0,
    GRAPHIC = 1,
} client_type_t;

/**
 * @struct client_s this structure represents a client in the game Zappy
 *
 * Each client has a socket, a type, a queue of asked actions,
 * a queue of answered actions, a unique ID, and a last tick action.
 */
typedef struct client_s {
    int socket;
    client_type_t type;

    char *buffer_asked; //we need to store the buffer of the asked actions
    char *buffer_answered;

    uuid_t uuid;
    size_t last_tick_action;
} client_t;

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_CLIENT_H
