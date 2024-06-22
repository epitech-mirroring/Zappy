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
    #include "incantation.h"
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
        array_t *incantations;
        bool win;
        char *winning_team;
        int food_spwan;
        size_t min_places;
        map_t *map;
    } game_t;

    /**
     * @brief Initialize a game
     *
     * @param teams The name of the teams in the game
     * @param map_size The size of the map [width, height]
     * @return game_t* The game
     */
    game_t *init_game(array_t *teams, size_t map_size[2], size_t min_places);

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

    /**
     * @brief Check if a team has won
     *
     * @param game The game
     */
    void check_win(game_t *game);

    /**
     * @brief Cast an incantation
     *
     * @param game The game
     * @param trantorian The trantorian
     */
    void cast_incantation(game_t *game, trantorian_t *trantorian);

    /**
     * @brief Update the tile player count when a player spawn
     *
     * @param egg The egg that is use by the player for spawn
     * @param team The team join by the player
     * @param game The game
     * @param i The index of the egg in the eggs array
     */
    void player_spawn(egg_t *egg, team_t *team, game_t *game, size_t i);

    /**
     * @brief Check if an incantation still be done
     *
     * @param game The game
     */
    void incantations_check(game_t *game);

    /**
     * @brief Remove a trantorian in the incantation it is part of
     * if it is part of one
     *
     * @param incantations The list of all the incantations
     * @param trantorian The trantorian to remove
     */
    void incantation_dead_trantorian(array_t *incantations,
        trantorian_t *trantorian);

    /**
     * @brief Check if an incantation can happend
     *
     * @param game The game
     * @param trantorians The list of the trantorians t
     * hat take part of the incantation
     * @param level The level of the incantation
     * @param pos The position where is the incantation
     */
    bool can_elevate(game_t *game, array_t *trantorians, size_t level,
        coordinates_t pos);

    /**
     * @brief Check if a team has the sum of the trantorians in
     * the team and the eggs of the team is >= of the minimum space
     * in the team
     *
     *@param game The game
     */
    void manage_teams_places(game_t *game);

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif //ZAPPY_GAME_H
