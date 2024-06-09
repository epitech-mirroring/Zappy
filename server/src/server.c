/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server.h"
#include "actions.h"

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
    server->clients = array_constructor(sizeof(client_t), (void *)&destroy_client);
    server->prev_tick_time = 0;
    server->nb_ticks = 0;
    server->port = port;
    server->max_fd = 0;
    return server;
}

void run(server_t *server)
{
    struct timeval tv;
    fd_set readfds;
    fd_set writefds;
    int ret;

    while (1) {
        tv.tv_sec = 0;
        tv.tv_usec = get_closest_action(server);
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        FD_SET(server->max_fd, &readfds);
        FD_SET(server->max_fd, &writefds);
        ret = select(server->max_fd + 1, &readfds, &writefds, NULL, &tv);
        if (ret == -1)
            break;
        tick(server);
        // add client management
    }
}

void add_client(server_t *server, int fd)
{
    client_t *client = init_client(fd, UNKNOWN);

    client->socket = fd;
    array_push(server->clients, &client);
    if (fd > server->max_fd)
        server->max_fd = fd;
}

void remove_client(server_t *server, int fd)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
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

void send_message(server_t *server, int fd, char *message)
{
    dprintf(fd, "%s\n", message);
}

void send_message_to_all(server_t *server, char *message)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        send_message(server, client->socket, message);
    }
}

void read_clients_messages(server_t *server)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        read_client_message(server, client);
    }
}

void read_client_message(server_t *server, client_t *client)
{
    char buffer[1024] = {0};
    int ret = read(client->socket, buffer, MAX_COMMAND_SIZE);

    if (ret <= 0)
        return;
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
            return;
        } else {
            client->type = AI;
        }
    }

}

int find_max_fd(server_t *server)
{
    int max_fd = 0;
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

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
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
