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
    size_t i = buffer->write_index;

    if (i == buffer->read_index) {
        i++;
        size--;
    }
    for (; size > 0; i++) {
        if (i >= buffer->capacity)
            i = 0;
        if ((i + 1 == buffer->read_index && size > 1) ||
            (i == buffer->capacity && buffer->read_index == 0 && size > 1))
            return false;
        size--;
    }
    if (size > 0)
        return false;
    return true;
}

buffer_t *create_buffer(size_t capacity, char limit)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    buffer->buffer = calloc(capacity, sizeof(char));
    for (size_t i = 0; i < capacity; i++)
        buffer->buffer[i] = limit;
    buffer->capacity = capacity;
    buffer->read_index = 0;
    buffer->write_index = 0;
    return buffer;
}

void buffer_write(buffer_t *buffer, char *data)
{
    size_t data_size = 0;

    if (buffer == NULL || data == NULL)
        return;
    data_size = strlen(data);
    if (!can_write(buffer, data_size))
        return;
    for (size_t i = 0; i < data_size; i++) {
        if (buffer->write_index == buffer->capacity) {
            buffer->write_index = 0;
        }
        if (data[i] == 13)
            continue;
        buffer->buffer[buffer->write_index] = data[i];
        buffer->write_index++;
    }
}

static int read_get_size(buffer_t *buffer, char limit)
{
    int data_size = 0;
    size_t i = 0;

    if (buffer == NULL)
        return 0;
    i = buffer->read_index;
    if (i == buffer->capacity)
            i = 0;
    while (buffer->buffer[i] != limit) {
        data_size++;
        i++;
        if (i == buffer->capacity)
            i = 0;
    }
    return data_size;
}

char *buffer_get_next(buffer_t *buffer, char limit)
{
    char *data;
    int data_size = 0;
    size_t i = 0;

    data_size = read_get_size(buffer, limit);
    if (data_size == 0)
        return NULL;
    data = calloc(data_size + 1, sizeof(char));
    if (buffer->read_index == buffer->capacity)
            buffer->read_index = 0;
    while (data_size > strlen(data)) {
        data[i] = buffer->buffer[buffer->read_index];
        buffer->buffer[buffer->read_index] = limit;
        buffer->read_index++;
        i++;
        if (buffer->read_index == buffer->capacity)
            buffer->read_index = 0;
    }
    buffer->read_index++;
    return data;
}

void buffer_clear(buffer_t *buffer)
{
    for (size_t i = 0; i < buffer->capacity; i++)
        buffer->buffer[i] = '\0';
    buffer->read_index = 0;
    buffer->write_index = 0;
}

void buffer_destroy(buffer_t *buffer)
{
    free(buffer->buffer);
    free(buffer);
}

bool buffer_is_empty(buffer_t *buffer)
{
    return buffer->read_index == buffer->write_index;
}
