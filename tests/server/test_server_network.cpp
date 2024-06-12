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
