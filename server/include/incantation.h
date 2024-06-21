/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** action include file for the trantorian
** action for the trantorian
*/

#ifndef ZAPPY_INCANTATION_H
    #define ZAPPY_INCANTATION_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    #include "array.h"
    #include "map.h"

/**
 * @struct Structure that stock the different things needed for elevated
 *
 * @param trantorians The trantorians concernred by the incantation
 * @param pos The position where the incantation is cast
 * @param level The level of the incantation
 */

    typedef struct incantation_s {
        array_t *trantorians;
        coordinates_t pos;
        size_t level;
        size_t couldown;
    } incantation_t;

    /**
     * @brief Init an incantation
     *
     * @param trantorians The trantorians array
     * @param pos The coodinates where is the incantation
     * @param level The level of the incantation
     */
    incantation_t *init_incantation(array_t *trantorians,
        coordinates_t pos, size_t level);

    /**
     * @brief Destroy an incantation
     *
     * @param incantation The incantation you want to destroy
     */
    void destroy_incantation(incantation_t *incantation);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_ACTIONS_H
