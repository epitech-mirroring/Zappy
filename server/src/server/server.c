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
