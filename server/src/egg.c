/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "egg.h"

egg_t *init_egg(uuid_t team_uuid, coordinates_t coordinates)
{
    egg_t *egg = malloc(sizeof(egg_t));

    uuid_copy(egg->team_uuid, team_uuid);
    egg->coordinates = coordinates;
    return egg;
}

void destroy_egg(egg_t *egg)
{
    if (egg == NULL)
        return;
    free(egg);
}
