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
    server->clients = array_constructor(sizeof(client_t),
        (void *)&destroy_client);
    server->nb_ticks = 0;
    server->port = port;
    server->max_fd = 0;
    if (create_socket(server) == -1)
        return NULL;
    return server;
}

void add_client(server_t *server, int fd)
{
    client_t *client = init_client(fd, UNKNOWN);

    client->socket = fd;
    buffer_write(client->buffer_answered, "WELCOME\n");
    array_push_back(server->clients, client);
    if (fd > server->max_fd)
        server->max_fd = fd;
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

void remove_client(server_t *server, int fd)
{
    client_t *client;
    size_t size = array_get_size(server->clients);

    for (size_t i = 0; i < size; i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (client->socket == fd) {
            array_remove(server->clients, i);
            break;
        }
    }
    if (fd == server->max_fd) {
        server->max_fd = 0;
        server->max_fd = find_max_fd(server);
    }
}
