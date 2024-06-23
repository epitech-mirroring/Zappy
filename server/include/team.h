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
        size_t free_places;
    } team_t;

    /**
     * @brief Initialize a team
     *
     * @param name The name of the team
     * @return team_t* The new team
     */
    team_t *init_team(char *name);

    /**
     * @brief Destroy a team
     *
     * @param team The team to destroy
     */
    void destroy_team(team_t *team);

    /**
     * @brief Add a Trantorian to a team
     *
     * @param team The team
     * @param trantorian The Trantorian to add
     */
    void add_trantorian_to_team(team_t *team, uuid_t trantorian);

    /**
     * @brief Return a string with the name of all the teams
     *
     * @param teams The array of teams
     * @return char* The string with the names of the teams
     */
    char *teams_to_string(array_t *teams);

    /**
     * @brief Check if a Trantorian is in a team
     *
     * @param trantorian The Trantorian
     * @param team The team
     * @return bool True if the Trantorian is in the team, false otherwise
     */
    bool is_in_team(trantorian_t *trantorian, team_t *team);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_TEAM_H
