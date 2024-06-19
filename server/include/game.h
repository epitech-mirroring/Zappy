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
        array_t *eggs;
        array_t *trantorians;
        array_t *clients_without_team;
        array_t *gui_log;
        array_t *gui_clients;
        bool win;
        char *winning_team;
        int food_spwan;

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

    /**
     * @brief Handle a new client that ask for an unknown team
     *
     * @param game The game
     * @param client The client
     * @param team_name The name of the team
     * @param index The index of the client in the array
     */
    void new_client_unknow_team(game_t *game,
        client_t *client, char *team_name, size_t index);

    // IA actions

    /**
 * @struct action_fnc_s
 *
 * This structure is used to store the function pointer that will be
 * called when the trantorian does an action
 * @param action the action that the trantorian can do
 * @param fnc the function pointer that will be called
 */

    typedef struct action_fnc_s {
        enum action_e action;
        void (*fnc)(game_t *game, trantorian_t *trantorian);
    } action_fnc_t;

    /**
     * @brief forward function, move the trantorian forward
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void forward(game_t *game, trantorian_t *trantorian);

    /**
     * @brief right function, move the trantorian to the right
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void right(game_t *game, trantorian_t *trantorian);

    /**
     * @brief left function, move the trantorian to the left
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void left(game_t *game, trantorian_t *trantorian);

    /**
     * @brief look function, look around the trantorian
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void look(game_t *game, trantorian_t *trantorian);

    /**
     * @brief inventory function, display the inventory of the trantorian
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void inventory(game_t *game, trantorian_t *trantorian);

    /**
     * @brief broadcast function, broadcast a message to the other trantorians
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void broadcast(game_t *game, trantorian_t *trantorian);

    /**
     * @brief connect_nbr function, display
     * the number of free places in the team
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void connect_nbr(game_t *game, trantorian_t *trantorian);

    /**
     * @brief fork function, create an egg
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void fork_ia(game_t *game, trantorian_t *trantorian);

    /**
     * @brief eject function, eject the trantorian from the tile
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void eject(game_t *game, trantorian_t *trantorian);

    /**
     * @brief take function, take an object from the tile
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void take(game_t *game, trantorian_t *trantorian);

    /**
     * @brief set function, set an object on the tile
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void set(game_t *game, trantorian_t *trantorian);

    /**
     * @brief incantation function, start the incantation
     *
     * @param game the game structure
     * @param trantorian the trantorian structure
     */
    void incantation(game_t *game, trantorian_t *trantorian);

    /**
     * @brief find_trantorian_action function,
     * find the action asked by the trantorians
     *
     * @param game the game structure
     */
    void find_trantorians_action(game_t *game);

    /**
     * @brief Check trantorians need to be set as dead
     *
     * @param game the game structure
     */
    void check_dead_trantorians(game_t *game);

    /**
     * @brief Destroy an egg when it's ejected
     *
     * @param game The game
     * @param egg The egg to destroy
     */
    void eject_egg(game_t *game, egg_t *egg);

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif //ZAPPY_GAME_H
