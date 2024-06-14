/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the eggs
** eggs for the zappy project
*/

#ifndef ZAPPY_EGG_H
    #define ZAPPY_EGG_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus
    #include "map.h"
    #include "uuid/uuid.h"

    /**
     * @struct egg_s
     *
     * This structure represents an egg laid by a Trantorian in the game Zappy.
     * Each egg has a unique ID, coordinates on the map, and belongs
     * to a specific team.
     */
    typedef struct egg_s {
        uuid_t team_uuid;
        coordinates_t coordinates;
    } egg_t;

    /**
     * @brief Initialize an egg
     *
     * @param team_uuid The team UUID
     * @param coordinates The coordinates of the egg
     * @return egg_t* The new egg
     */
    egg_t *init_egg(uuid_t team_uuid, coordinates_t coordinates);

    /**
     * @brief Destroy an egg
     *
     * @param egg The egg to destroy
     */
    void destroy_egg(egg_t *egg);

    /**
     * @brief Generate a new egg with random coordinates
     *
     * @param team_uuid The team UUID
     * @param map The map
     * @return egg_t* The new egg
     */
    egg_t *generate_egg(uuid_t team_uuid, map_t *map);

    /**
     * @brief Genrate the start eggs for the game
     *
     * @param game The game
     */
    void generate_start_eggs(game_t *game);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_EGG_H
