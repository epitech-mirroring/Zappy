/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_SERVER_H
    #define ZAPPY_SERVER_H

    #define MAX_COMMAND_SIZE 1024
    #define MAX_USERS 10000

    #include "game.h"
    #include "array.h"
    #include "client.h"
    #include "buffer.h"
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

        size_t single_tick_time; // in microseconds
        long long nb_ticks; // number of ticks

        unsigned short port;
        int max_fd;
        int fd;
    } server_t;

    /**
     * @brief Initialize a server
     *
     * @param port The port on which the server will listen
     * @param freq The frequency of the server
     * @return server_t* The server
     */
    server_t *create_server(unsigned short port, array_t *teams,
        size_t map_size[2], size_t nb_max_clients);

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
     * @param fd The file descriptor of the client
     */
    void add_client(server_t *server, int fd);

    /**
     * @brief Remove a client from the server
     *
     * @param server The server
     * @param fd The file descriptor of the client
     */
    void remove_client(server_t *server, int fd);

    /**
     * @brief Read a client message
     *
     * @param server The server
     * @param client The client
     */
    void read_client_message(server_t *server, client_t *client);

    /**
     * @brief Execute client command (only network command)
     *
     * @param server The server
     * @param client The client
     */
    void new_clients_check(server_t *server, client_t *client);

    /**
     * @brief Find the max file descriptor
     *
     * @param server The server
     */
    int find_max_fd(server_t *server);

    /**
     * @brief Handle new connections
     *
     * @param server The server
     * @param readfds The fd_set for the read file descriptors
     */
    void handle_new_connections(server_t *server, fd_set *readfds);

    /**
     * @brief write to clients
     *
     * @param server The server
     */
    void write_to_clients(server_t *server);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_SERVER_H
