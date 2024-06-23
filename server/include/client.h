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
    #include "buffer.h"
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
        UNKNOWN = 2
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
        bool need_to_be_kick;

        buffer_t *buffer_asked;
        buffer_t *buffer_answered;
    } client_t;

    /**
     * @brief Initialize a client
     *
     * @param socket The socket of the client
     * @param type The type of the client
     * @return client_t* The client
     */
    client_t *init_client(int socket, client_type_t type);

    /**
     * @brief Destroy a client
     *
     * @param client The client to destroy
     */
    void destroy_client(client_t *client);

    /**
     * @brief Add message to the buffer of the client
     *
     * @param client The target client
     * @param message The message to add
     */
    void add_message(client_t *client, char *message);

    /**
     * @brief Get the next message from the buffer of the client
     *
     * @param client The target client
     * @return char* The message
     */
    char *get_next_message(client_t *client);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_CLIENT_H
