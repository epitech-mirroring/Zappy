/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <string.h>
#include "game.h"
#include "actions.h"

#ifndef IA_ACTIONS_H
    #define IA_ACTIONS_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    #include <stddef.h>
    /**
     * @brief Look around the player
     *
     * @param tile The tile to look at
     *
     * @return char* The message to send to the player
     */
    char *get_element_on_tile(tile_t *tile, hashmap_t *content);

    /**
     * @brief Look around the player in north direction
     *
     * @param game The game
     * @param level the level of current player
     * @param player_coordinates the coordinates of the player
     *
     * @return the message to send to the player
     */
    char *look_north(game_t *game, short level,
        coordinates_t player_coordinates, hashmap_t *content);

    /**
     * @brief Look around the player in south direction
     *
     * @param game The game
     * @param level the level of current player
     * @param player_coordinates the coordinates of the player
     *
     * @return the message to send to the player
     *
     */
    char *look_south(game_t *game, short level,
        coordinates_t player_coordinates, hashmap_t *content);

    /**
     * @brief Look around the player in east direction
     *
     * @param game The game
     * @param level the level of current player
     * @param player_coordinates the coordinates of the player
     *
     * @return the message to send to the player
     */
    char *look_east(game_t *game, short level,
        coordinates_t player_coordinates, hashmap_t *content);

    /**
     * @brief Look around the player in west direction
     *
     * @param game The game
     * @param level the level of current player
     * @param player_coordinates the coordinates of the player
     *
     * @return the message to send to the player
     */
    char *look_west(game_t *game, short level,
        coordinates_t player_coordinates, hashmap_t *content);


    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif // IA_ACTIONS_H
