/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <stdio.h>
#include <string.h>
#include "client.h"
#include "buffer.h"
#include "game.h"
#include "array.h"
#include "team.h"
#include "trantorian.h"
#include "gui.h"

const action_fnc_t actions_fnc[] = {
    {FORWARD, &forward},
    {RIGHT, &right},
    {LEFT, &left},
    {LOOK, &look},
    {INVENTORY, &inventory},
    {BROADCAST, &broadcast},
    {CONNECT_NBR, &connect_nbr},
    {FORK, &fork_ia},
    {EJECT, &eject},
    {TAKE, &take},
    {SET, &set},
    {INCANTATION, &incantation},
    {-1, NULL}
};

static team_t *get_team_by_name(array_t *teams, char *team_name)
{
    team_t *team = NULL;

    for (size_t i = 0; i < array_get_size(teams); i++) {
        team = (team_t *)array_get_at(teams, i);
        if (strcmp(team->name, team_name) == 0)
            return team;
    }
    return NULL;
}

static bool can_create_trantorian(game_t *game, char *team_name)
{
    team_t *team = NULL;

    team = get_team_by_name(game->teams, team_name);
    if (team == NULL)
        return false;
    if (team->free_places <= 0)
        return false;
    for (size_t i = 0; i < array_get_size(game->eggs); i++) {
        if (uuid_compare(((egg_t *)array_get_at
            (game->eggs, i))->team_uuid, team->uuid) == 0)
            return true;
    }
    return false;
}

static void trantorian_action(game_t *game, trantorian_t *trantorian)
{
    size_t i = 0;
    action_t action;

    if (array_get_size(trantorian->actions) == 0)
        return;
    if (trantorian->waiting_tick > 0)
        return;
    if (trantorian->is_dead)
        return;
    while (actions_fnc[i].action != -1) {
        action = *(action_t *)array_get_at(trantorian->actions, 0);
        if (actions_fnc[i].action == action.action) {
            actions_fnc[i].fnc(game, trantorian);
            array_remove(trantorian->actions, 0);
            return;
        }
        i++;
    }
}

static char *int_to_str(int nb)
{
    char *str = calloc(sizeof(char), 12);

    sprintf(str, "%d", nb);
    return str;
}

static void new_client_ping(game_t *game, client_t *client,
    team_t *team, trantorian_t *trantorian)
{
    char *msg = calloc(1024, sizeof(char));
    char *uuid = calloc(37, sizeof(char));
    char *dir = strdup(get_direction_str(trantorian->direction));
    coordinates_t pos = trantorian->coordinates;

    snprintf(msg, 1024, "%i\n", team->free_places);
    buffer_write(client->buffer_answered, msg);
    snprintf(msg, 1024, "%i %i\n", game->map->width, game->map->height);
    buffer_write(client->buffer_answered, msg);
    uuid_unparse(trantorian->uuid, uuid);
    snprintf(msg, 1024, "pnw %s %d %d %s %d %s\n", uuid, pos.x, pos.y,
        dir, 1, team->name);
    array_push_back(game->gui_log, msg);
    free(dir);
    free(uuid);
}

void handle_new_client(game_t *game)
{
    client_t *client = NULL;
    char *msg = NULL;
    trantorian_t *trantorian = NULL;

    for (size_t i = 0; i < array_get_size(game->clients_without_team); i++) {
        client = (client_t *)array_get_at(game->clients_without_team, i);
        msg = buffer_get_next(client->buffer_asked, '\n');
        if (msg == NULL)
            continue;
        if (can_create_trantorian(game, msg)) {
            create_trantorian(game,
                get_team_by_name(game->teams, msg), client);
            trantorian = (trantorian_t *)array_get_at
                (game->trantorians, array_get_size(game->trantorians) - 1);
            new_client_ping(game, client,
                get_team_by_name(game->teams, msg), trantorian);
            array_remove(game->clients_without_team, i);
        } else
            new_client_unknow_team(game, client, msg, i);
    }
}

game_t *init_game(array_t *teams, size_t map_size[2], size_t min_places)
{
    game_t *game = malloc(sizeof(game_t));

    game->teams = array_constructor(sizeof(team_t), (void *)&destroy_team);
    game->gui_log = array_constructor(sizeof(char *), (void *)&free);
    game->gui_clients = array_constructor(sizeof(client_t), NULL);
    game->incantations =
        array_constructor(sizeof(incantation_t), (void *)&destroy_incantation);
    for (size_t i = 0; i < array_get_size(teams); i++) {
        array_push_back(game->teams, array_get_at(teams, i));
    }
    game->eggs = array_constructor(sizeof(egg_t), (void *)&destroy_egg);
    game->trantorians = array_constructor(sizeof(trantorian_t), NULL);
    game->map = init_map(map_size[0], map_size[1]);
    generate_start_eggs(game);
    generate_ressources(game->map);
    game->clients_without_team = array_constructor(sizeof(client_t), NULL);
    game->win = false;
    game->food_spwan = 0;
    game->min_places = min_places;
    return game;
}

void destroy_game(game_t *game)
{
    array_destructor(game->teams);
    array_destructor(game->eggs);
    array_destructor(game->trantorians);
    array_destructor(game->clients_without_team);
    array_destructor(game->gui_log);
    array_destructor(game->gui_clients);
    destroy_map(game->map);
    free(game->winning_team);
    free(game);
}

void game_tick(game_t *game)
{
    trantorian_t *trantorian = NULL;

    game->food_spwan++;
    if (game->food_spwan == 20) {
        generate_ressources(game->map);
        game->food_spwan = 0;
    }
    if (game->win || array_get_size(game->trantorians) == 0)
        return;
    check_dead_trantorians(game);
    find_trantorians_action(game);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(game->trantorians, i);
        trantorian_tick(trantorian);
        trantorian_action(game, trantorian);
    }
    manage_teams_places(game);
    check_win(game);
}

void create_trantorian(game_t *game, team_t *team, client_t *client)
{
    trantorian_t *trantorian;
    egg_t *egg;
    int i = 0;

    for (i = 0; i < array_get_size(game->eggs); i++) {
        if (uuid_compare(((egg_t *)array_get_at
            (game->eggs, i))->team_uuid, team->uuid) == 0) {
            break;
        }
    }
    if (i == array_get_size(game->eggs))
        return;
    egg = (egg_t *)array_get_at(game->eggs, i);
    trantorian = init_trantorian(egg->coordinates, client);
    array_push_back(team->trantorians, trantorian->uuid);
    array_push_back(game->trantorians, trantorian);
    ebo_log_gui(game, egg);
    player_spawn(egg, team, game, i);
}
