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
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus
    /**
     * @struct server_s
     *
     * This structure represents a server in the game Zappy.
     * Each server has a game, a list of clients, a single tick time,
     * a previous tick time, a number of ticks, and a port.
     *
     */
    typedef struct server_s {
        game_t *game;
        array_t *clients;

        size_t single_tick_time;
        size_t prev_tick_time;
        size_t nb_ticks;

        unsigned short port;
    } server_t;

    /**
     * @brief Initialize a server
     *
     * @param port The port on which the server will listen
     * @param freq The frequency of the server
     * @return server_t* The server
     */
    server_t *init(unsigned short port, size_t freq);

    /**
     * @brief Destroy a server
     *
     * @param server The server to destroy
     */
    void destroy(server_t *server);

    /**
     * @brief Run the server
     *
     * @param server The server to run
     */

    void run(server_t *server);

    /**
     * @brief Add a client to the server
     *
     * @param server The server
     * @param client The client to add
     */
    void reader(server_t *server);

    /**
     * @brief Remove a client from the server
     *
     * @param server The server
     */
    void writer(server_t *server);

    /**
     * @brief Check if a client is dead and remove it from the client list
     *
     * @param server The server
     */
    void check_dead_clients(server_t *server);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_SERVER_H
