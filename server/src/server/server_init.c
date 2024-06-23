/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example.
** You can even have multiple lines if you want !
*/

#include "server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

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
    free(addr);
    return 0;
}

void destroy(server_t *server)
{
    destroy_game(server->game);
    array_destructor(server->clients);
    free(server);
}

server_t *create_server(unsigned short port, array_t *teams,
                        size_t map_size[2], size_t min_free_places)
{
    server_t *server = malloc(sizeof(server_t));
    team_t *team;

    if (!server)
        return NULL;
    for (size_t i = 0; i < array_get_size(teams); i++) {
            team = (team_t *)array_get_at(teams, i);
            team->free_places = min_free_places;
        }
    server->game = init_game(teams, map_size, min_free_places);
    server->clients = array_constructor(sizeof(client_t *),
                                        (void *)&destroy_client);
    server->port = port;
    server->max_fd = 0;
    if (create_socket(server) == -1)
        return NULL;
    return server;
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
            bool is_empty = buffer_is_empty(client->buffer_answered);
            if (!is_empty) {
                    FD_SET(client->socket, writefds);
                } else {
                    FD_SET(client->socket, readfds);
                }
        }
}
