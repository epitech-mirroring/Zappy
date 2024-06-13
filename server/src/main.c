/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server.h"
#include "team.h"
#include "array.h"
#include <string.h>

static size_t *find_map_size(int ac, char **av)
{
    int i = 1;
    size_t *map_size;

    for (; i < ac && strcmp(av[i], "-x") != 0; i++);
    if (i >= ac)
        return NULL;
    map_size = malloc(sizeof(size_t) * 2);
    map_size[0] = atoi(av[i + 1]);
    for (i = 1; i < ac && strcmp(av[i], "-y") != 0; i++);
    if (i >= ac) {
        free(map_size);
        return NULL;
    }
    map_size[1] = atoi(av[i + 1]);
    return map_size;
}

static unsigned short find_port(int ac, char **av)
{
    int i = 1;

    for (; i < ac; i++) {
        if (strcmp(av[i], "-p") == 0)
            break;
    }
    if (i >= ac)
        return -1;
    return atoi(av[i + 1]);
}

static int find_nb_max_clients(int ac, char **av)
{
    int i = 1;

    for (; i < ac; i++) {
        if (strcmp(av[i], "-c") == 0)
            break;
    }
    if (i >= ac)
        return -1;
    return atoi(av[i + 1]);
}

static size_t find_single_tick_time(int ac, char **av)
{
    int i = 1;

    for (; i < ac; i++) {
        if (strcmp(av[i], "-f") == 0)
            break;
    }
    if (i >= ac)
        return -1;
    return 1000000 / atoi(av[i + 1]);
}

static array_t *find_teams(int ac, char **av)
{
    int i = 1;
    array_t *teams = array_constructor(sizeof(team_t *), NULL); //need to implement team destructor

    for (; i < ac; i++) {
        if (strcmp(av[i], "-n") == 0)
            break;
    }
    if (i >= ac)
        return NULL;
    for (i++; i < ac && av[i][0] != '-'; i++) {
        array_push_back(teams, NULL); // need to implement team constructor
    }
    return teams;
}

int main(int ac, char **av)
{
    size_t *map_size = find_map_size(ac, av);
    unsigned short port = find_port(ac, av);
    int nb_max_clients = find_nb_max_clients(ac, av);
    size_t single_tick_time = find_single_tick_time(ac, av);
    array_t *teams = find_teams(ac, av);
    server_t *server;

    if (map_size == NULL || port == -1 || nb_max_clients == -1
        || single_tick_time == -1 || teams == NULL)
        return 84;
    server = init(port, teams, map_size, nb_max_clients);
    if (server == NULL)
        return 84;
    server->single_tick_time = single_tick_time;
    run(server);
    printf("Server is running\n");
    destroy(server);
    return 0;
}
