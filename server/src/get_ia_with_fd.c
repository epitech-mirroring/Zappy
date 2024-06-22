/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example.
** You can even have multiple lines if you want !
*/

#include "game.h"

trantorian_t *get_ia_with_fd(game_t *game, int fd)
{
    trantorian_t *ia = NULL;

    for (size_t i = 0; i < array_get_size(game->trantorians); i++) {
        ia = (trantorian_t *)array_get_at(game->trantorians, i);
        if (ia->client->socket == fd)
            return ia;
    }
    return NULL;
}
