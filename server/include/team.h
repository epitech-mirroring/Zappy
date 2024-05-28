/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** team include file for the trantorian
** team for the trantorian
*/

#ifndef ZAPPY_TEAM_H
#define ZAPPY_TEAM_H

/**
 * @struct s_team
 *
 * This structure represents a team in the game Zappy.
 * Each team has a unique ID, a name, a number of members, and an array of Trantorians.
 */
typedef struct s_team {
    int id;
    char *name;
    int menber_count;
    t_trantorian *members;
} t_team;

#endif //ZAPPY_TEAM_H
