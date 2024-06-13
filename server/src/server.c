/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example.
** You can even have multiple lines if you want !
*/

#include "server.h"
#include "actions.h"
#include <bits/waitflags.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void add_client(server_t *server, int fd)
{
    client_t *client = init_client(fd, UNKNOWN);

    client->socket = fd;
    buffer_write(client->buffer_answered, "WELCOME\n");
    array_push_back(server->clients, client);
    if (fd > server->max_fd)
        server->max_fd = fd;
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

static void read_clients_messages(server_t *server, fd_set *readfds)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (FD_ISSET(client->socket, readfds))
            read_client_message(server, client);
    }
}

void run(server_t *server)
{
    struct timeval tv;
    struct timeval *tv2;
    fd_set readfds;
    fd_set writefds;

    while (1) {
        tv.tv_sec = 0;
        tv.tv_usec = get_closest_action(server);
        fill_fd_set(server, &readfds, &writefds);
        if (tv.tv_usec == -1)
            tv2 = NULL;
        else
            tv2 = &tv;
        if (select(server->max_fd + 1, &readfds, &writefds, NULL, tv2) == -1)
            return;
        handle_new_connections(server, &readfds);
        read_clients_messages(server, &readfds);
        while (waitpid(-1, NULL, WNOHANG) > 0);
        tick(server, tv.tv_usec);
    }
}

void read_client_message(server_t *server, client_t *client)
{
    char buffer[1024] = {0};
    size_t ret = read(client->socket, buffer, MAX_COMMAND_SIZE);
    if (ret <= 0)
        return;
    printf("buffer: %s\n", buffer);
    add_message(client, buffer);
}

void new_clients_check(server_t *server, client_t *client)
{
    char *message = get_next_message(client);

    if (!message)
        return;
    if (client->type == UNKNOWN) {
        if (strcmp(message, "GRAPHIC") == 0) {
            client->type = GRAPHIC;
        } else {
            client->type = AI;
            array_push_back(server->game->clients_without_team, client);
        }
    }
}

int find_max_fd(server_t *server)
{
    int max_fd = server->fd;
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (client->socket > max_fd)
            max_fd = client->socket;
    }
    return max_fd;
}

__suseconds_t get_closest_action(server_t *server)
{
    __suseconds_t closest_action = -1;
    __suseconds_t action;
    trantorian_t *trantorian;
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (client->type != AI)
            continue;
        trantorian =
            (trantorian_t *)array_get_at(server->game->trantorians, i);
            action = (__suseconds_t)trantorian->waiting_tick
                * server->single_tick_time * 1000;
            if ((closest_action == -1 || action < closest_action)
                && action >= 0)
                closest_action = action;
    }
    return closest_action;
}
