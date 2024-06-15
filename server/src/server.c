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

static void write_to_client(client_t *client)
{
    char *message = buffer_get_next(client->buffer_answered);

    for (; message != NULL; message =
        buffer_get_next(client->buffer_answered)) {
        send(client->socket, message, strlen(message), 0);
        free(message);
    }
}

static void tick(server_t *server, __suseconds_t time_since_last_tick)
{
    int nb_ticks = time_since_last_tick / server->single_tick_time;

    if (nb_ticks <= 0)
        return;
    if (time_since_last_tick == -1)
        nb_ticks = 0;
    handle_new_client(server->game);
    for (int i = 0; i < nb_ticks; i++) {
        game_tick(server->game);
    }
    write_to_clients(server);
    server->nb_ticks += nb_ticks;
}

static void read_clients_messages(server_t *server, fd_set *readfds)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (FD_ISSET(client->socket, readfds)) {
            read_client_message(server, client);
            new_clients_check(server, client);
        }
    }
}

static __suseconds_t get_closest_action(server_t *server)
{
    __suseconds_t closest_action = -1;
    __suseconds_t action;
    trantorian_t *trantorian;

    for (size_t i = 0; i < array_get_size(server->game->trantorians); i++) {
        trantorian = (trantorian_t *)
            array_get_at(server->game->trantorians, i);
        if (array_get_size(trantorian->actions) == 0)
            continue;
        action = trantorian->waiting_tick * server->single_tick_time;
        if (action != -1 && (closest_action == -1 || action < closest_action))
            closest_action = action;
    }
    return closest_action;
}

static void fill_fd_set(server_t *server, fd_set *readfds, fd_set *writefds)
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

void write_to_clients(server_t *server)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        write_to_client(client);
    }
}

void read_client_message(server_t *server, client_t *client)
{
    char buffer[1024] = {0};
    size_t ret = read(client->socket, buffer, MAX_COMMAND_SIZE);

    if (ret <= 0)
        return;
    add_message(client, buffer);
}

void new_clients_check(server_t *server, client_t *client)
{
    char *message;

    if (client->type != UNKNOWN) {
        return;
    }
    message = get_next_message(client);
    if (!message)
        return;
    if (strcmp(message, "GRAPHIC") == 0) {
        client->type = GRAPHIC;
    } else {
        client->type = AI;
        buffer_write(client->buffer_asked, message);
        array_push_back(server->game->clients_without_team, client);
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
