/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests for buffer.c
*/

#include <gtest/gtest.h>
#include "buffer.h"
#include <string>

TEST(BufferTests, test_buffer_create)
{
    buffer_t *buffer = create_buffer(1024);

    ASSERT_EQ(buffer->capacity, 1024);
    ASSERT_EQ(buffer->read_index, 0);
    ASSERT_EQ(buffer->write_index, 0);
}

TEST(BufferTests, test_buffer_write)
{
    buffer_t *buffer = create_buffer(1024);
    char *data = strdup("Hello, World!");

    buffer_write(buffer, data);
    ASSERT_EQ(buffer->buffer[0], 'H');
    ASSERT_EQ(buffer->buffer[1], 'e');
    ASSERT_EQ(buffer->buffer[2], 'l');
    ASSERT_EQ(buffer->buffer[3], 'l');
    ASSERT_EQ(buffer->buffer[4], 'o');
    ASSERT_EQ(buffer->buffer[5], ',');
    ASSERT_EQ(buffer->buffer[6], ' ');
    ASSERT_EQ(buffer->buffer[7], 'W');
    ASSERT_EQ(buffer->buffer[8], 'o');
    ASSERT_EQ(buffer->buffer[9], 'r');
    ASSERT_EQ(buffer->buffer[10], 'l');
    ASSERT_EQ(buffer->buffer[11], 'd');
    ASSERT_EQ(buffer->buffer[12], '!');
    ASSERT_EQ(buffer->buffer[13], '\0');
    ASSERT_EQ(buffer->write_index, 14);
}

TEST(BufferTests, test_buffer_get_next)
{
    buffer_t *buffer = create_buffer(1024);
    char *data = strdup("Hello, World!");

    buffer_write(buffer, data);
    char *next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 14);
}

TEST(BufferTests, test_buffer_get_next_with_multiple_data)
{
    buffer_t *buffer = create_buffer(1024);
    char *data = strdup("Hello, World!");

    buffer_write(buffer, data);
    buffer_write(buffer, data);
    char *next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 14);
    next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 28);
}

TEST(BufferTests, test_buffer_get_next_with_data_wrapping)
{
    buffer_t *buffer = create_buffer(1024);
    char *data = strdup("Hello, World!");

    buffer_write(buffer, data);
    buffer_write(buffer, data);
    char *next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 14);
    next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 28);
    buffer_write(buffer, data);
    next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 42);
}

TEST(BufferTests, test_buffer_get_next_with_no_data)
{
    buffer_t *buffer = create_buffer(1024);
    char *next_data = buffer_get_next(buffer);

    ASSERT_EQ(next_data, nullptr);
    ASSERT_EQ(buffer->read_index, 0);
}

TEST(BufferTests, test_buffer_get_next_with_no_data_and_data_wrapping)
{
    buffer_t *buffer = create_buffer(1024);
    char *data = strdup("Hello, World!");

    buffer_write(buffer, data);
    buffer_write(buffer, data);
    char *next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 14);
    next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, data);
    ASSERT_EQ(buffer->read_index, 28);
    next_data = buffer_get_next(buffer);
    ASSERT_STREQ(next_data, nullptr);
    ASSERT_EQ(buffer->read_index, 28);
}

TEST(BufferTests, test_buffer_write_over_limit)
{
    buffer_t *buffer = create_buffer(6);
    char *data = strdup("test");

    buffer_write(buffer, data);
    ASSERT_EQ(buffer->buffer[0], 't');
    ASSERT_EQ(buffer->buffer[1], 'e');
    ASSERT_EQ(buffer->buffer[2], 's');
    ASSERT_EQ(buffer->buffer[3], 't');
    ASSERT_EQ(buffer->buffer[4], '\0');
    ASSERT_EQ(buffer->write_index, 5);
    char *data2 = buffer_get_next(buffer);
    ASSERT_STREQ(data2, data);
    buffer_write(buffer, data);
    ASSERT_EQ(buffer->buffer[5], 't');
    ASSERT_EQ(buffer->buffer[0], 'e');
    ASSERT_EQ(buffer->buffer[1], 's');
    ASSERT_EQ(buffer->buffer[2], 't');
    ASSERT_EQ(buffer->buffer[3], '\0');
    ASSERT_EQ(buffer->write_index, 4);
}
