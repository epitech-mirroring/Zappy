/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** action include file for the trantorian
** action for the trantorian
*/


#ifndef ZAPPY_ACTIONS_H
#define ZAPPY_ACTIONS_H

/**
 * @enum e_action
 *
 * This enumeration is used to store the different actions that a trantorian can do
 */
enum e_action {
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
 * @struct s_action
 *
 * This structure is used to store the action of the trantorian
 * Each action has a type and a time to start and a wait time
 */
typedef struct s_action {
    enum e_action action;
    int time_start;
    int wait_time;
} t_action;

/**
 * @struct s_action_list
 *
 * This structure is used to store the action of the trantorian
 * Each action has a type and a time to start and a wait time
 */
typedef struct s_actions_list {
    size_t size;
    t_action *actions;
    struct s_action_list *next;
} t_action_list;

#endif //ZAPPY_ACTIONS_H
