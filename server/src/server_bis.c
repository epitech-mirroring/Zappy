/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server.h"

void destroy(server_t *server)
{
    destroy_game(server->game);
    array_destructor(server->clients);
    free(server);
}

server_t *init(unsigned short port, array_t *teams,
    size_t map_size[2], size_t nb_max_clients)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        return NULL;
    server->game = init_game(teams, map_size, nb_max_clients);
    server->clients = array_constructor(sizeof(client_t),
        (void *)&destroy_client);
    server->nb_ticks = create_number_with_int(0);
    server->port = port;
    server->max_fd = 0;
    return server;
}

void tick(server_t *server, __suseconds_t time_since_last_tick)
{
    int nb_ticks = time_since_last_tick / server->single_tick_time;

    if (nb_ticks <= 0)
        return;
    for (int i = 0; i < nb_ticks; i++) {
        game_tick(server->game);
    }
    add_int_to_number(server->nb_ticks, nb_ticks);
}
