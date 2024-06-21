/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

client_t *init_client(int socket, client_type_t type)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->socket = socket;
    client->type = type;
    client->buffer_asked = create_buffer(100000, '\n');
    client->buffer_answered = create_buffer(100000, '\n');
    client->need_to_be_kick = false;
    return client;
}

void destroy_client(client_t *client)
{
    buffer_destroy(client->buffer_asked);
    buffer_destroy(client->buffer_answered);
    free(client);
}

void add_message(client_t *client, char *message)
{

    if (client == NULL)
        return;
    buffer_write(client->buffer_asked, message);
}

char *get_next_message(client_t *client)
{
    if (client == NULL)
        return NULL;
    return buffer_get_next(client->buffer_asked, '\n');
}

static void dead_client(server_t *server, client_t *client)
{
    (void)server;
    close(client->socket);
}

void check_dead_client(server_t *server)
{
    client_t *client;
    client_t *tmp;

    for (size_t i = 0; i < array_get_size(server->clients); i++) {
        client = (client_t *)array_get_at(server->clients, i);
        if (client->need_to_be_kick == true) {
            tmp = client;
            array_remove(server->clients, i);
            dead_client(server, tmp);
            destroy_client(tmp);
        }
    }
}
