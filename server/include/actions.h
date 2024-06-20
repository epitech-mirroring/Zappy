/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** action include file for the trantorian
** action for the trantorian
*/


#ifndef ZAPPY_ACTIONS_H
    #define ZAPPY_ACTIONS_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    #include <stddef.h>

/**
 * @enum action_e
 *
 * This enumeration is used to store the different actions that a
 * trantorian can do
 */
    enum action_e {
        FORWARD,
        RIGHT,
        LEFT,
        LOOK,
        INVENTORY,
        BROADCAST,
        CONNECT_NBR,
        FORK,
        EJECT,
        TAKE,
        SET,
        INCANTATION
    };

/**
 * @struct action_s
 *
 * This structure is used to store the action that a trantorian can do
 * and the time it takes to do it
 * @param action the action that the trantorian can do
 * @param time the time it takes to do the action
 * @param action_name the name of the action
*/

    typedef struct action_s {
        enum action_e action;
        size_t time;
        char *action_name;
    } action_t;

/**
 * @struct incantaion_check_s
 *
 * This structure is used to store the incantation check
 * @param level the level of the incantation
 * @param player the number of player needed to do the incantation
 * @param linemate the number of linemate needed to do the incantation
 * @param deraumere the number of deraumere needed to do the incantation
 * @param sibur the number of sibur needed to do the incantation
 * @param mendiane the number of mendiane needed to do the incantation
 * @param phiras the number of phiras needed to do the incantation
 * @param thystame the number of thystame needed to do the incantation
 */

    typedef struct incantation_check_s {
        size_t level;
        size_t player;
        size_t linemate;
        size_t deraumere;
        size_t sibur;
        size_t mendiane;
        size_t phiras;
        size_t thystame;
    } incantation_check_t;

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_ACTIONS_H
