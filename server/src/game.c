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

static void trantorian_action(game_t *game, trantorian_t *trantorian)
{
    //TODO: Implement trantorian actions
}

static char *int_to_str(int nb)
{
    char *str = calloc(sizeof(char), 12);

    sprintf(str, "%d", nb);
    return str;
}

static void new_client_ping(game_t *game, client_t *client,
    team_t *team, coordinates_t pos)
{
    char *msg = NULL;

    msg = int_to_str(team->free_places);
    strcat(msg, "\n");
    buffer_write(client->buffer_answered, msg);
    free(msg);
    msg = int_to_str(pos.x);
    strcat(msg, " ");
    strcat(msg, int_to_str(pos.y));
    strcat(msg, "\n");
    buffer_write(client->buffer_answered, msg);
    free(msg);
}

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

static void handle_new_client(game_t *game)
{
    client_t *client = NULL;
    char *msg = NULL;
    trantorian_t *trantorian = NULL;

    for (size_t i = 0; i < array_get_size(game->clients_without_team); i++) {
        client = (client_t *)array_get_at(game->clients_without_team, i);
        msg = buffer_get_next(client->buffer_asked);
        if (msg == NULL)
            continue;
        if (can_create_trantorian(game, msg)) {
            create_trantorian(game,
                get_team_by_name(game->teams, msg), client);
            trantorian = (trantorian_t *)array_get_at
                (game->trantorians, array_get_size(game->trantorians) - 1);
            new_client_ping(game, client,
                get_team_by_name(game->teams, msg), trantorian->coordinates);
            array_remove(game->clients_without_team, i);
        } else
            buffer_write(client->buffer_answered, "ko\n");
    }
}

game_t *init_game(array_t *teams, size_t map_size[2])
{
    game_t *game = malloc(sizeof(game_t));

    game->teams = array_constructor(sizeof(team_t), (void *)&destroy_team);
    for (size_t i = 0; array_get_size(teams); i++) {
        array_push_back(game->teams, array_get_at(teams, i));
    }
    game->eggs = array_constructor(sizeof(egg_t), (void *)&destroy_egg);
    generate_start_eggs(game);
    game->trantorians = array_constructor(sizeof(trantorian_t), NULL);
    game->map = init_map(map_size[0], map_size[1]);
    generate_ressources(game->map);
    return game;
}

void destroy_game(game_t *game)
{
    if (game == NULL)
        return;
    array_destructor(game->teams);
    array_destructor(game->eggs);
    array_destructor(game->trantorians);
    destroy_map(game->map);
    free(game);
}

void game_tick(game_t *game)
{
    trantorian_t *trantorian = NULL;

    handle_new_client(game);
    generate_ressources(game->map);
    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        trantorian = (trantorian_t *)array_get_at(game->trantorians, i);
        // trantorian_tick(trantorian); //TODO: Implement trantorian_tick
        if (trantorian->waiting_tick == 0)
            trantorian_action(game, trantorian);
    }
}

void create_trantorian(game_t *game, team_t *team, client_t *client)
{
    trantorian_t *trantorian;
    int i = 0;

    for (i = 0; i < array_get_size(game->eggs); i++) {
        if (uuid_compare(((egg_t *)array_get_at
            (game->eggs, i))->team_uuid, team->uuid) == 0) {
            break;
        }
    }
    if (i == array_get_size(game->eggs))
        return;
    trantorian = init_trantorian(((egg_t *)array_get_at
        (game->eggs, i))->coordinates, client);
    if (trantorian == NULL)
        return;
    array_push_back(team->trantorians, trantorian->uuid);
    array_push_back(game->trantorians, trantorian);
    array_remove(game->eggs, i);
    team->free_places--;
}

bool can_create_trantorian(game_t *game, char *team_name)
{
    team_t *team = get_team_by_name(game->teams, team_name);

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
