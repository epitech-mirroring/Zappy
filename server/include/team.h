/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** team include file for the trantorian
** team for the trantorian
*/

#ifndef ZAPPY_TEAM_H
    #define ZAPPY_TEAM_H

    #include "trantorian.h"
    #include "array.h"
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    /**
     * @struct team_s
     *
     * This structure represents a team in the game Zappy.
     * Each team has a unique ID, a name, a number of members,
     * and an array of Trantorians.
     */
    typedef struct team_s {
        uuid_t uuid;
        array_t *trantorians;
        char *name;
    } team_t;

    /**
     * @brief Initialize a team
     *
     * @param name The name of the team
     * @return team_t* The new team
     */
    team_t *init_team(char *name);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_TEAM_H
