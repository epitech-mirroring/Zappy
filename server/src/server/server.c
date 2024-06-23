/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example.
** You can even have multiple lines if you want !
*/

#include "server.h"
#include "actions.h"
#include <sys/select.h>
#include <sys/time.h>

static struct timeval get_timeout(server_t *server)
{
    int us = get_closest_action(server);
    long int s = 0;
    struct timeval tv = {0, 0};

    if (us < 0)
        return tv;
    s = us / 1000000;
    us = us % 1000000;
    tv.tv_sec = s;
    tv.tv_usec = us;
    return tv;
}

void run(server_t *server)
{
    struct timeval tv = {0, 0};
    fd_set readfds;
    fd_set writefds;

    is_server_running(true, true);
    while (is_server_running(false, false)) {
        fill_fd_set(server, &readfds, &writefds);
        tv = get_timeout(server);
        if (select(server->max_fd + 1, &readfds, &writefds, NULL, &tv) == -1)
            return;
        handle_new_connections(server, &readfds);
        read_clients_messages(server, &readfds);
        tick(server, &writefds);
    }
}
