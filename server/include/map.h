/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the map
** map for the zappy project
*/

#ifndef ZAPPY_MAP_H
#define ZAPPY_MAP_H

/**
 * @struct s_coordinates
 *
 * This structure represents the coordinates of a tile on the map.
 * Each tile has an x and y coordinate.
 */
typedef struct s_coordinates
    int x;
    int y;
} t_coordinates;

/**
 * @struct s_resources
 *
 * This structure represents the resources on a tile on the map.
 * Each tile has a quantity of food, linemate, deraumere, sibur, mendiane, phiras, and thystame.
 */
typedef struct resources {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} t_resources;

/**
 * @struct s_tile
 *
 * This structure represents a tile on the map.
 * Each tile has coordinates, a player count, and resources.
 */
typedef struct s_tile {
    t_coordinates coordinates;
    int player_count;
    t_resources resources;
} t_tile;

/**
 * @struct s_map
 *
 * This structure represents the map of the game.
 * The map has a width, a height, and a 2D array of tiles.
 */
typedef struct s_map {
    int width;
    int height;
    t_tile **tiles;
} t_map;

#endif //ZAPPY_MAP_H
