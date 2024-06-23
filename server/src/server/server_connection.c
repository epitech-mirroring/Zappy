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
#include <sys/time.h>
#include <netinet/in.h>


static void time_value(server_t *server, size_t *elapsed_ticks, size_t elapsed_us,
                       size_t will_sub);

int get_closest_action(server_t *server)
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

static void calculate_time(server_t *server, size_t *elapsed_ticks)
{
    struct timeval tv = {0, 0};
    size_t actual_time = tv.tv_sec * 1000000 + tv.tv_usec;
    size_t elapsed_us = actual_time - server->prev_tick_time;
    size_t will_sub = 0;
    struct timeval current = {0, 0};

    gettimeofday(&tv, NULL);
    time_value(server, elapsed_ticks, elapsed_us, will_sub);
    if (*elapsed_ticks > 0)
        for (size_t i = 0; i < *elapsed_ticks; i++) {
            gettimeofday(&current, NULL);
            server->prev_tick_time = current.tv_sec * 1000000 + current.tv_usec;
        }
}

static void time_value(server_t *server, size_t *elapsed_ticks,
    size_t elapsed_us, size_t will_sub)
{
    while (elapsed_us > 0) {
        will_sub = MIN(server->remaining_us_before_next_tick,
            elapsed_us);
        server->remaining_us_before_next_tick -= will_sub;
        elapsed_us -= will_sub;
        if (server->remaining_us_before_next_tick == 0) {
            server->remaining_us_before_next_tick = server->single_tick_time;
            (*elapsed_ticks)++;
        }
    }
}

static void update_game(server_t *server, fd_set *write_fds, size_t elapsed_ticks)
{
    handle_new_client(server->game);
    if (elapsed_ticks > 0) {
        for (size_t i = 0; i < elapsed_ticks; i++) {
            game_tick(server->game);
        }
    }
    run_gui_commands(server);
    update_graphic_clients_buffer(server);
    write_to_clients(server, write_fds);
    find_trantorians_action(server->game);
    check_dead_client(server);
}

void tick(server_t *server, fd_set *write_fds)
{
    size_t elapsed_ticks = 0;
    calculate_time(server, &elapsed_ticks);
    update_game(server, write_fds, elapsed_ticks);
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
