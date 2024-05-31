/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** action include file for the trantorian
** action for the trantorian
*/


#ifndef ZAPPY_ACTIONS_H
    #define ZAPPY_ACTIONS_H

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

/**
 * @struct action_s
 *
 * This structure is used to store the action of the trantorian
 * Each action has a type and a time to start and a wait time
 */
typedef struct action_s {
    enum action_e action;
    int time_start;
    int wait_time;
} action_t;

/**
 * @struct actions_list_s
 *
 * This structure is used to store the action of the trantorian
 * Each action has a type and a time to start and a wait time
 */
typedef struct actions_list_s {
    size_t size;
    action_t *actions;
    struct action_s_list *next;
} action_list_t;

#endif //ZAPPY_ACTIONS_H
