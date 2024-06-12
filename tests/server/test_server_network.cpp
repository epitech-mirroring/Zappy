/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <gtest/gtest.h>
#include "server.h"

size_t map_size[2] = {10, 10};

TEST(Server, init)
{
    server_t *server = init(4242, nullptr, map_size, 10);

    ASSERT_NE(server, nullptr);
    ASSERT_EQ(server->port, 4242);
    // ASSERT_EQ(server->game->map->height, 10);
    // ASSERT_EQ(server->game->map->width, 10);
    ASSERT_EQ(server->max_fd, 0);
    destroy(server);
}

TEST(Server, destroy)
{
    server_t *server = init(4242, NULL, map_size, 10);

    destroy(server);
}

TEST(Infinite_number, init)
{
    number_t *number = create_number_with_int(0);

    ASSERT_NE(number, nullptr);
    ASSERT_EQ(number->number[0], 0);
    destroy_number(number);
}

TEST(Infinite_number, get_size_of_int)
{
    ASSERT_EQ(get_size_of_int(0), 1);
    ASSERT_EQ(get_size_of_int(1), 1);
    ASSERT_EQ(get_size_of_int(10), 2);
    ASSERT_EQ(get_size_of_int(100), 3);
}

TEST(Infinite_number, add_numbers)
{
    number_t *number1 = create_number_with_int(0);
    number_t *number2 = create_number_with_int(1);

    add_numbers(number1, number2);
    ASSERT_EQ(number1->number[0], 1);
    destroy_number(number1);
    destroy_number(number2);
}

TEST(Infinite_number, create_number_with_string)
{
    char nb[] = "1234567890";
    number_t *number = create_number_with_string(nb);

    ASSERT_NE(number, nullptr);
    ASSERT_EQ(number->number, nb);
    destroy_number(number);
}

TEST(Infinite_number, add_int_to_number)
{
    number_t *number = create_number_with_int(0);

    add_int_to_number(number, 1);
    ASSERT_EQ(number->number[0], 1);
    destroy_number(number);
}

TEST(Infinite_number, subtract_int_to_number)
{
    number_t *number = create_number_with_int(1);

    subtract_int_to_number(number, 1);
    ASSERT_EQ(number->number[0], 0);
    destroy_number(number);
}

TEST(Infinite_number, compare_int_to_number)
{
    number_t *number = create_number_with_int(1);

    ASSERT_EQ(compare_int_to_number(number, 1), 0);
    ASSERT_EQ(compare_int_to_number(number, 0), 1);
    ASSERT_EQ(compare_int_to_number(number, 2), -1);
    destroy_number(number);
}

TEST(Server, add_client)
{
    server_t *server = init(4242, NULL, map_size, 10);

    add_client(server, 1);
    ASSERT_EQ(server->max_fd, 1);
    ASSERT_EQ(array_get_size(server->clients), 1);
    destroy(server);
}

TEST(Server, remove_client)
{
    server_t *server = init(4242, NULL, map_size, 10);

    add_client(server, 1);
    remove_client(server, 1);
    ASSERT_EQ(server->max_fd, 0);
    destroy(server);
}
