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

    enum direction_e {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    typedef struct direction_to_string_s {
        enum direction_e direction;
        char *str;
    } direction_to_string_t;

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
        size_t nb_waiting_actions;
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

     /**
     * @brief Return a string representation of the inventory
     *
     * @param inventory The inventory to represent
     * @return char* The string representation of the inventory
    */
    char *inventory_to_str(trantorian_t *trantorian);

    /**
     * @brief Return a string representation of the trantorian position
     *
     * @param trantorian The trantorian to represent
     * @return char* The string representation of the trantorian position
    */
    char *trantorian_pos_to_str(trantorian_t *trantorian);

    /**
     * @brief Return a string representation of the trantorian level
     *
     * @param trantorian The trantorian to represent
     * @return char* The string representation of the trantorian level
    */
    char *trantorian_level_to_str(trantorian_t *trantorian);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_TRANTORIAN_H
