/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_TRANTORIAN_H
    #define ZAPPY_TRANTORIAN_H

    #include <stdio.h>
    #include <uuid/uuid.h>
    #include "inventory.h"
    #include "actions.h"
    #include "client.h"

    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    /**
     * @struct coordinates_s
     *
     * This structure represents the coordinates of a tile on the map.
     * Each tile has an x and y coordinate.
     */
    enum direction_e {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    /**
     * @struct trantorian_s
     *
     * this structure represents a trantorian in the game Zappy
     * Each trantorian has a unique ID, coordinates on the map,
     * a level, an inventory, an action list, a direction, and a team.
     */
    typedef struct trantorian_s {
        uuid_t uuid;
        coordinates_t coordinates;
        size_t level;
        inventory_t inventory;
        array_t *actions;
        enum direction_e direction;
        size_t waiting_tick;
        client_t *client;
    } trantorian_t;

    /**
     * @brief Initialize a trantorian
     *
     * @param coordinates The coordinates of the trantorian
     * @param client The client associated with the trantorian
     * @return trantorian_t* The trantorian
     */
    trantorian_t *init_trantorian(coordinates_t coordinates, client_t *client);

    /**
     * @brief Destroy a trantorian
     *
     * @param trantorian The trantorian to destroy
     */
    void destroy_trantorian(trantorian_t *trantorian);

    /**
     * @brief Trantorian tick
     *
     * @param trantorian The trantorian to tick
     */
    void trantorian_tick(trantorian_t *trantorian);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_TRANTORIAN_H
