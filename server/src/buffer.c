/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** buffer for the network
*/

#include "buffer.h"

buffer_t *create_buffer(size_t capacity)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    buffer->buffer = malloc(capacity);
    buffer->capacity = capacity;
    buffer->read_index = 0;
    buffer->write_index = 0;
    return buffer;
}

void buffer_write(buffer_t *buffer, char *data)
{
    int len = strlen(data);

    if (!can_write(buffer, len))
        return;
    for (int i = 0; i < len; i++) {
        if (buffer->write_index == buffer->capacity)
            buffer->write_index = 0;
        buffer->buffer[buffer->write_index] = data[i];
        buffer->write_index++;
    }
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
    data = malloc(data_size + 1);
    for (size_t i = 0; buffer->buffer[buffer->read_index] != '\0'; i++) {
        if (buffer->read_index == buffer->capacity)
            buffer->read_index = 0;
        data[i] = buffer->buffer[buffer->read_index];
        buffer->buffer[buffer->read_index] = '\0';
        buffer->read_index++;
    }
    data[data_size] = '\0';
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

static bool can_write(buffer_t *buffer, size_t size)
{
    if (size >= buffer->capacity)
        return false;
    for (int i = buffer->write_index; i != buffer->read_index; i++) {
        if (i == buffer->capacity)
            i = 0;
        size--;
    }
    if (size > 0)
        return false;
    return true;
}
