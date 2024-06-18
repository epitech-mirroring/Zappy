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
    #include "client.h"
    #include "team.h"
    #include <stdbool.h>

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
        array_t *clients_without_team;
        array_t *gui_log;
        bool win;
        char *winning_team;

        map_t *map;
    } game_t;

    /**
     * @brief Initialize a game
     *
     * @param teams The name of the teams in the game
     * @param map_size The size of the map [width, height]
     * @return game_t* The game
     */
    game_t *init_game(array_t *teams, size_t map_size[2]);

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
     * @brief Create a Trantorian for a team
     *
     * @param game The game
     * @param team_name The name of the team
     * @param client The client that wants to create a Trantorian
     */
    void create_trantorian(game_t *game, team_t *team, client_t *client);

    /**
     * @brief Genrate the start eggs for the game
     *
     * @param game The game
     */
    void generate_start_eggs(game_t *game);

    /**
     * @brief Handle a new client
     *
     * @param game The game
     */
    void handle_new_client(game_t *game);

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif //ZAPPY_GAME_H
