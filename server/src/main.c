/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <string.h>
#include <time.h>
#include "server.h"
#include "team.h"
#include "array.h"

static size_t *find_map_size(int ac, char **av)
{
    int i = 1;
    size_t *map_size;

    while (i < ac && strcmp(av[i], "-x") != 0) {
        i++;
    }
    if (i >= ac)
        return NULL;
    map_size = malloc(sizeof(size_t) * 2);
    map_size[0] = atoi(av[i + 1]);
    i = 1;
    while (i < ac && strcmp(av[i], "-y") != 0) {
        i++;
    }
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
    array_t *teams = array_constructor(sizeof(team_t *),
        (void *)&destroy_team);

    for (; i < ac; i++) {
        if (strcmp(av[i], "-n") == 0)
            break;
    }
    if (i >= ac)
        return NULL;
    for (i++; i < ac && av[i][0] != '-'; i++) {
        array_push_back(teams, init_team(av[i]));
    }
    return teams;
}

int check_teams(array_t *teams)
{
    team_t *team;
    int check = 1;

    if (array_get_size(teams) == 0)
        return 84;
    for (size_t i = 0; i < array_get_size(teams); i++) {
        team = (team_t *)array_get_at(teams, i);
        if (team->name == NULL || strcmp(team->name, "GRAPHIC") == 0)
            return 84;
        check = 1;
        for (size_t j = i + 1; j < array_get_size(teams) && check != 0; j++) {
            check = strcmp(team->name,
                ((team_t *)array_get_at(teams, j))->name);
        }
        if (check == 0)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    size_t *map_size = find_map_size(ac, av);
    unsigned short port = find_port(ac, av);
    int nb_max_clients = find_nb_max_clients(ac, av);
    size_t single_tick_time = find_single_tick_time(ac, av);
    array_t *teams = find_teams(ac, av);
    server_t *server;

    if (sigaction_init() == 84)
        return 84;
    srand(time(NULL));
    if (map_size == NULL || nb_max_clients == -1
        || single_tick_time > (size_t)1000000 || check_teams(teams) == 84)
        return 84;
    server = create_server(port, teams, map_size, nb_max_clients);
    if (server == NULL)
        return 84;
    server->single_tick_time = single_tick_time;
    run(server);
    shutdown_server(server);
    destroy(server);
    return 0;
}
