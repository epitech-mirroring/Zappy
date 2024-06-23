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
#include <sys/socket.h>
#include <string.h>

void add_client(server_t *server, int fd)
{
    client_t *client = init_client(fd, UNKNOWN);

    client->socket = fd;
    buffer_write(client->buffer_answered, "WELCOME\n");
    array_push_back(server->clients, client);
    if (fd > server->max_fd)
        server->max_fd = fd;
}

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

void write_to_clients(server_t *server, fd_set *write_fds)
{
    client_t *client;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
            client = (client_t *)array_get_at(server->clients, i);
            if (FD_ISSET(client->socket, write_fds))
                write_to_client(client);
        }
}

static void read_client_message(server_t *server, client_t *client)
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

void read_clients_messages(server_t *server, fd_set *readfds)
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

void remove_client(server_t *server, int fd)
{
    client_t *client;
    size_t size = array_get_size(server->clients);

    for (size_t i = 0; i < size; i++) {
            client = (client_t *)array_get_at(server->clients, i);
            if (client->socket == fd) {
                    array_remove(server->clients, i);
                    destroy_client(client);
                    break;
                }
        }
    if (fd == server->max_fd) {
            server->max_fd = 0;
            server->max_fd = find_max_fd(server);
        }
}
