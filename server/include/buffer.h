/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** buffer for the client
*/


#ifndef ZAPPY_BUFFER_H
    #define ZAPPY_BUFFER_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    #define BUFFER_CAPACITY 4096

    #include <stdbool.h>
    #include <stdlib.h>

    /**
     * @struct buffer_s
     * This structure represents a circular buffer.
     * Each buffer has a buffer, a capacity, a read index, and a write index.
     */
    typedef struct buffer_s {
        char *buffer;
        int capacity;
        int read_index;
        int write_index;
    } buffer_t;

    /**
     * @brief Create a buffer
     *
     * @param capacity The capacity of the buffer
     * @return buffer_t* The buffer
     */
    buffer_t *create_buffer(size_t capacity, char limit);

    /**
     * @brief Write data to the buffer
     *
     * @param buffer The buffer to write to
     * @param data The data to write
     */
    void buffer_write(buffer_t *buffer, char *data);

    /**
     * @brief Get the next data from the buffer
     *
     * @param buffer The buffer to get the data from
     * @return char* The data
     */
    char *buffer_get_next(buffer_t *buffer, char limit);

    /**
     * @brief Destroy a buffer
     *
     * @param buffer The buffer to destroy
     */
    void buffer_destroy(buffer_t *buffer);

    #ifdef __cplusplus
}

    #endif // __cplusplus

#endif //ZAPPY_BUFFER_H
