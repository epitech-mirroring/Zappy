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
    server_t *init(unsigned short port, size_t freq,
        array_t *teams, int map_size[2]);

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
     * @param message The message received from the client
     */
    void add_client(server_t *server, int fd, char *message);

    /**
     * @brief Remove a client from the server
     *
     * @param server The server
     * @param fd The file descriptor of the client
     */
    void remove_client(server_t *server, int fd);

    /**
     * @brief Send a message to a client
     *
     * @param server The server
     * @param fd The file descriptor of the client
     * @param message The message to send
     */
    void send_message(server_t *server, int fd, char *message);

    /**
     * @brief Send a message to all clients
     *
     * @param server The server
     * @param message The message to send
     */
    void send_message_to_all(server_t *server, char *message);

    /**
     * @brief Read client messages that have not been read yet
     *
     * @param server The server
     */
    void read_clients_messages(server_t *server);

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
    void execute_client_command(server_t *server, client_t *client);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_SERVER_H
