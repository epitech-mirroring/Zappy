/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** buffer for the network
*/

#define BUFFER_CAPACITY 4096

#ifndef ZAPPY_BUFFER_H
    #define ZAPPY_BUFFER_H

    #include <stdbool.h>
    #include <stdlib.h>

    typedef struct buffer_s {
        char *buffer;
        int capacity;
        int read_index;
        int write_index;
    } buffer_t;

    buffer_t *create_buffer(size_t capacity);
    void buffer_write(buffer_t *buffer, char *data);
    char *buffer_get_next(buffer_t *buffer);
    void buffer_destroy(buffer_t *buffer);
    bool can_write(buffer_t *buffer, size_t size);

#endif //ZAPPY_BUFFER_H
