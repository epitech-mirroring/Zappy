/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "trantorian.h"

char *trantorian_pos_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);

    sprintf(str, "ppo %s %d %d %d\n", trantorian->uuid, trantorian->coordinates.x,
        trantorian->coordinates.y, trantorian->direction);
    return str;
}

char *trantorian_level_to_str(trantorian_t *trantorian)
{
    char *str = malloc(sizeof(char) * 100);

    sprintf(str, "plv %s %d\n", trantorian->uuid, trantorian->level);
    return str;
}
