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

static void connect_server(server_t *server)
{
    struct sockaddr_in *addr = malloc(sizeof(struct sockaddr_in));

    addr->sin_family = AF_INET;
    addr->sin_port = htons(server->port);
    addr->sin_addr.s_addr = INADDR_ANY;
    bind(server->fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server->fd, MAX_USERS);

}

void destroy(server_t *server)
{
    destroy_game(server->game);
    array_destructor(server->clients);
    free(server);
}

server_t *init(unsigned short port, array_t *teams,
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
    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    connect_server(server);
    return server;
}

void tick(server_t *server, __suseconds_t time_since_last_tick)
{
    int nb_ticks = time_since_last_tick / server->single_tick_time;

    if (nb_ticks <= 0)
        return;
    for (int i = 0; i < nb_ticks; i++) {
        game_tick(server->game);
    }
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
