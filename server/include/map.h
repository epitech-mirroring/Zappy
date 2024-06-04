/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the map
** map for the zappy project
*/

#ifndef ZAPPY_MAP_H
    #define ZAPPY_MAP_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus
/**
 * @struct coordinates_s
 *
 * This structure represents the coordinates of a tile on the map.
 * Each tile has an x and y coordinate.
 */
typedef struct coordinates_s {
    int x;
    int y;
} coordinates_t;

/**
 * @struct s_resources
 *
 * This structure represents the resources on a tile on the map.
 * Each tile has a quantity of food, linemate, deraumere, sibur, mendiane, phiras, and thystame.
 */
typedef struct resources_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} resources_t;

/**
 * @struct tile_s
 *
 * This structure represents a tile on the map.
 * Each tile has coordinates, a player count, and resources.
 */
typedef struct tile_s {
    coordinates_t coordinates;
    int player_count;
    resources_t resources;
    array_t *eggs;
} tile_t;

/**
 * @struct map_s
 *
 * This structure represents the map of the game.
 * The map has a width, a height, and a 2D array of tiles.
 */
typedef struct map_s {
    int width;
    int height;
    tile_t **tiles;
} map_t;

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_MAP_H
