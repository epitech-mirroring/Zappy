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
 * This enumeration is used to store the different actions that a trantorian can do
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
    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_ACTIONS_H
