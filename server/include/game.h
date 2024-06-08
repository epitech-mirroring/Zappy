/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_GAME_H
    #define ZAPPY_GAME_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus
    #include "array.h"
    #include "map.h"
    #include "trantorian.h"
    #include "egg.h"
    #include <stdbool.h>
    #include "client.h"

    /**
     * @struct game_s
     *
     * This structure represents a game in the game Zappy.
     * Each game has an array of teams, an array of eggs, an array
     * of Trantorians, and a map.
     *
     */
    typedef struct game_s {
        array_t *teams;
        array_t *eggs; //array of pointers to eggs stored in the map
        array_t *trantorians;

        map_t *map;
    } game_t;

    /**
     * @brief Initialize a game
     *
     * @param teams The name of the teams in the game
     * @param map_size The size of the map [width, height]
     * @param team_max_size The maximum size of a team
     * @return game_t* The game
     */
    game_t *init_game(array_t *teams, size_t map_size[2],
        size_t team_max_size);

    /**
     * @brief Destroy a game
     *
     * @param game The game to destroy
     */
    void destroy_game(game_t *game);

    /**
     * @brief Run the game in one tick
     *
     * @param game The game to run
     */
    void game_tick(game_t *game);

    /**
     * @brief Check if a team can create a Trantorian
     *
     * @param game The game
     * @param team_name The name of the team
     * @return bool true if the team is not full, false otherwise
     */
    bool can_create_trantorian(game_t *game, char *team_name);

    /**
     * @brief Create a Trantorian for a team
     *
     * @param game The game
     * @param team_name The name of the team
     * @param client The client that wants to create a Trantorian
     */
    void create_trantorian(game_t *game, char *team_name, client_t *client);

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif //ZAPPY_GAME_H
