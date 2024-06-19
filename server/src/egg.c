/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "egg.h"
#include "game.h"
#include "gui.h"

egg_t *init_egg(uuid_t team_uuid, coordinates_t coordinates)
{
    egg_t *egg = malloc(sizeof(egg_t));

    uuid_copy(egg->team_uuid, team_uuid);
    uuid_generate(egg->uuid);
    egg->coordinates = coordinates;
    return egg;
}

void destroy_egg(egg_t *egg)
{
    if (egg == NULL)
        return;
    free(egg);
}

egg_t *generate_egg(uuid_t team_uuid, map_t *map)
{
    egg_t *egg = malloc(sizeof(egg_t));
    coordinates_t coordinates = {rand() % map->width, rand() % map->height};

    uuid_copy(egg->team_uuid, team_uuid);
    egg->coordinates = coordinates;
    uuid_generate(egg->uuid);
    return egg;
}

void generate_start_eggs(game_t *game)
{
    team_t *team = NULL;

    for (size_t i = 0; i < array_get_size(game->teams); i++) {
        team = (team_t *)array_get_at(game->teams, i);
        for (size_t j = 0; j < team->free_places; j++) {
            array_push_back(game->eggs, generate_egg(team->uuid, game->map));
        }
    }
}

void eject_egg(game_t *game, egg_t *egg)
{
    team_t *team = NULL;

    for (size_t i = 0; i < array_get_size(game->teams); i++) {
        team = (team_t *)array_get_at(game->teams, i);
        if (uuid_compare(egg->team_uuid, team->uuid) == 0) {
            team->free_places--;
            break;
        }
    }
    printf("team %s has lost an egg\n", team->name);
    edi_log_gui(game, egg);
    destroy_egg(egg);
}
