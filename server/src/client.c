/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <stdio.h>
#include "client.h"
#include "buffer.h"


client_t *init_client(int socket, client_type_t type)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return (NULL);
    client->socket = socket;
    client->type = type;
    client->buffer_asked = create_buffer(100000);
    client->buffer_answered = create_buffer(100000);
    return (client);
}

void destroy_client(client_t *client)
{
    if (client == NULL)
        return;
    buffer_destroy(client->buffer_asked);
    buffer_destroy(client->buffer_answered);
    free(client);
}

void add_message(client_t *client, char *message)
{
    char *new_message = calloc(sizeof(char), strlen(message) - 1);

    if (client == NULL)
        return;
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '\n' || message[i] == '\r')
            continue;
        new_message[i] = message[i];
    }
    buffer_write(client->buffer_asked, new_message);
    free(new_message);
}

char *get_next_message(client_t *client)
{
    if (client == NULL)
        return (NULL);
    return buffer_get_next(client->buffer_asked);
}

client_type_t get_type(client_t *client)
{
    if (client->type == GRAPHIC)
        return (GRAPHIC);
    else if (client->type == AI)
        return (AI);
    return (UNKNOWN);
}
