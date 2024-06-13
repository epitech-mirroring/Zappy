/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

static void write_to_client(client_t *client)
{
    char *message = buffer_get_next(client->buffer_answered);

    for (; message != NULL; message =
        buffer_get_next(client->buffer_answered)) {
        send(client->socket, message, strlen(message), 0);
        free(message);
    }
}

static void write_to_clients(server_t *server)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        write_to_client(client);
    }
}

static int create_socket(server_t *server)
{
    struct sockaddr_in *addr = malloc(sizeof(struct sockaddr_in));
    int opt = 1;

    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->fd == -1)
        return -1;
    addr->sin_family = AF_INET;
    addr->sin_port = htons(server->port);
    addr->sin_addr.s_addr = INADDR_ANY;
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &opt,
                   sizeof(opt)) == -1)
        return -1;
    if (bind(server->fd, (struct sockaddr *)addr, sizeof(*addr)) == -1 ||
            listen(server->fd, MAX_USERS) == -1)
        return -1;
    return 0;
}

void destroy(server_t *server)
{
    destroy_game(server->game);
    array_destructor(server->clients);
    free(server);
}

server_t *create_server(unsigned short port, array_t *teams,
                        size_t map_size[2], size_t nb_max_clients)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        return NULL;
    server->game = init_game(teams, map_size, nb_max_clients);
    server->clients = array_constructor(sizeof(client_t),
        (void *)&destroy_client);
    server->nb_ticks = 0;
    server->port = port;
    server->max_fd = 0;
    if (create_socket(server) == -1)
        return NULL;
    return server;
}

void tick(server_t *server, __suseconds_t time_since_last_tick)
{
    int nb_ticks = time_since_last_tick / server->single_tick_time;

    if (nb_ticks <= 0)
        return;
    if (time_since_last_tick == -1)
        nb_ticks = 0;
    for (int i = 0; i < nb_ticks; i++) {
        game_tick(server->game);
    }
    write_to_clients(server);
    server->nb_ticks += nb_ticks;
}

void fill_fd_set(server_t *server, fd_set *readfds, fd_set *writefds)
{
    client_t *client;

    FD_ZERO(readfds);
    FD_ZERO(writefds);
    FD_SET(server->fd, readfds);
    server->max_fd = find_max_fd(server);
    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        FD_SET(client->socket, readfds);
        FD_SET(client->socket, writefds);
    }
}

void handle_new_connections(server_t *server, fd_set *readfds)
{
    int new_fd = 0;
    struct sockaddr_in addr;
    socklen_t size = sizeof(addr);

    if (FD_ISSET(server->fd, readfds)) {
        new_fd = accept(server->fd, (struct sockaddr *)&addr, &size);
        add_client(server, new_fd);
    }
}
