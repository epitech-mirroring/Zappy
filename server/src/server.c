/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example.
** You can even have multiple lines if you want !
*/

#include "server.h"
#include "gui.h"
#include "actions.h"
#include <stdint.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/time.h>

static void write_to_client(client_t *client)
{
    char *message = buffer_get_next(client->buffer_answered, '\n');
    char *tmp = NULL;

    while (message != NULL) {
        tmp = calloc(strlen(message) + 2, sizeof(char));
        sprintf(tmp, "%s\n", message);
        send(client->socket, tmp, strlen(tmp), MSG_NOSIGNAL);
        free(message);
        free(tmp);
        message = buffer_get_next(client->buffer_answered, '\n');
    }
    free(message);
}

static void tick(server_t *server, fd_set *write_fds)
{
    struct timeval tv = {0, 0};
    gettimeofday(&tv, NULL);
    size_t actual_time = tv.tv_sec * 1000000 + tv.tv_usec;
    size_t elapsed_us = actual_time - server->prev_tick_time;
    size_t elapsed_ticks = 0;
    struct timeval current = {0, 0};

    while (elapsed_us > 0) {
        size_t will_sub = MIN(server->remaining_us_before_next_tick, elapsed_us);
        server->remaining_us_before_next_tick -= will_sub;
        elapsed_us -= will_sub;
        if (server->remaining_us_before_next_tick == 0) {
            server->remaining_us_before_next_tick = server->single_tick_time;
            elapsed_ticks++;
        }
    }
    handle_new_client(server->game);
    if (elapsed_ticks > 0) {
        for (size_t i = 0; i < elapsed_ticks; i++) {
            gettimeofday(&current, NULL);
            server->prev_tick_time = current.tv_sec * 1000000 + current.tv_usec;
            game_tick(server->game);
        }
    }
    run_gui_commands(server);
    update_graphic_clients_buffer(server);
    write_to_clients(server, write_fds);
    find_trantorians_action(server->game);
    check_dead_client(server);
}

static void read_clients_messages(server_t *server, fd_set *readfds)
{
    client_t *client;
    size_t size = array_get_size(server->clients);

    for (size_t i = 0; i < size; i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (FD_ISSET(client->socket, readfds)) {
            read_client_message(server, client);
            new_clients_check(server, client);
        }
    }
}

static int get_closest_action(server_t *server)
{
    int closest_action = INT32_MAX;
    int next_action_in;
    trantorian_t *trantorian;
    size_t nb_trants = array_get_size(server->game->trantorians);
    int refill_in = 20 - server->game->food_spwan;

    for (size_t i = 0; i < nb_trants; i++) {
        trantorian = (trantorian_t *)
                array_get_at(server->game->trantorians, i);
        if (array_get_size(trantorian->actions) == 0)
            continue;
        next_action_in = (int)
                (trantorian->waiting_tick * server->single_tick_time);
        if (next_action_in < closest_action)
            closest_action = next_action_in;
    }
    if ((int)(refill_in * server->single_tick_time) < closest_action)
        closest_action = (int) (refill_in * server->single_tick_time);
    return (int) (closest_action - server->remaining_us_before_next_tick);
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
        bool is_empty = buffer_is_empty(client->buffer_answered);
        if (!is_empty) {
            FD_SET(client->socket, writefds);
        } else {
            FD_SET(client->socket, readfds);
        }
    }
}

void run(server_t *server)
{
    struct timeval tv = {0, 0};
    fd_set readfds;
    fd_set writefds;

    is_server_running(true, true);
    while (is_server_running(false, false)) {
        struct timeval current = {0, 0};
        gettimeofday(&current, NULL);
        int us = get_closest_action(server);
        long int s = us / 1000000;
        us = us % 1000000;
        tv.tv_sec = s;
        tv.tv_usec = us;
        fill_fd_set(server, &readfds, &writefds);
        if (select(server->max_fd + 1, &readfds, &writefds, NULL, &tv) == -1)
            return;
        handle_new_connections(server, &readfds);
        read_clients_messages(server, &readfds);
        tick(server, &writefds);
    }
}

void write_to_clients(server_t *server, fd_set *write_fds)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (FD_ISSET(client->socket, write_fds))
            write_to_client(client);
    }
}

void read_client_message(server_t *server, client_t *client)
{
    char buffer[1024] = {0};
    size_t ret = recv(client->socket, buffer, MAX_COMMAND_SIZE, 0);
    trantorian_t *trantorian;

    if (ret > 0) {
        add_message(client, buffer);
        return;
    }
    if (client->type != AI) {
        remove_client(server, client->socket);
    } else {
        trantorian = get_ia_with_fd(server->game, client->socket);
        if (trantorian)
            trantorian->is_dead = true;
    }
}

void new_clients_check(server_t *server, client_t *client)
{
    char *message;
    char *tmp = calloc(1024, sizeof(char));

    if (client->type != UNKNOWN) {
        free(tmp);
        return;
    }
    message = get_next_message(client);
    sprintf(tmp, "%s\n", message);
    if (!message)
        return;
    if (strcmp(message, "GRAPHIC") == 0) {
        client->type = GRAPHIC;
    } else {
        client->type = AI;
        buffer_write(client->buffer_asked, tmp);
        array_push_back(server->game->clients_without_team, client);
    }
    free(message);
    free(tmp);
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
