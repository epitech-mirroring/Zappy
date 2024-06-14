/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** buffer for the network
*/

#include "buffer.h"
#include <string.h>
#include <stdio.h>

static bool can_write(buffer_t *buffer, size_t size)
{
    if (buffer->write_index + size >= buffer->capacity)
        return false;
    return true;
}

buffer_t *create_buffer(size_t capacity)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    buffer->buffer = calloc(capacity, sizeof(char));
    buffer->capacity = capacity;
    buffer->read_index = 0;
    buffer->write_index = 0;
    return buffer;
}

void buffer_write(buffer_t *buffer, char *data)
{
    size_t data_size = strlen(data);

    if (!can_write(buffer, data_size))
        return;
    if (data[0] == '\0' || data[0] == '\n' || data[0] == '\r')
        return;
    for (size_t i = 0; i < data_size; i++) {
        if (buffer->write_index == buffer->capacity)
            buffer->write_index = 0;
        if (data[i] == 13)
            continue;
        buffer->buffer[buffer->write_index] = data[i];
        buffer->write_index++;
    }
    buffer->buffer[buffer->write_index] = '\0';
    buffer->write_index++;
}

char *buffer_get_next(buffer_t *buffer)
{
    char *data;
    int data_size = 0;

    for (int i = buffer->read_index; buffer->buffer[i] != '\0'; i++) {
        if (i == buffer->capacity)
            i = 0;
        data_size++;
    }
    if (data_size == 0)
        return NULL;
    data = calloc(data_size + 1, sizeof(char));
    for (size_t i = 0; buffer->buffer[buffer->read_index] != '\0'; i++) {
        if (buffer->read_index == buffer->capacity)
            buffer->read_index = 0;
        data[i] = buffer->buffer[buffer->read_index];
        buffer->buffer[buffer->read_index] = '\0';
        buffer->read_index++;
    }
    buffer->read_index++;
    return data;
}

void buffer_clear(buffer_t *buffer)
{
    for (int i = 0; i < buffer->capacity; i++)
        buffer->buffer[i] = '\0';
    buffer->read_index = 0;
    buffer->write_index = 0;
}

void buffer_destroy(buffer_t *buffer)
{
    free(buffer->buffer);
    free(buffer);
}
