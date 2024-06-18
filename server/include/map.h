/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file of the map
** map for the zappy project
*/

#ifndef ZAPPY_MAP_H

    #include "array.h"
    #include "hashmap.h"

    #define ZAPPY_MAP_H


    #ifdef __cplusplus


extern "C" {
    #endif // __cplusplus

    typedef struct ressources_map_s {
        char *name;
        int density;
    } ressources_map_t;

    /**
     * @struct coordinates_s
     *
     * This structure represents the coordinates of a tile on the map.
     * Each tile has an x and y coordinate.
     */
    typedef struct coordinates_s {
        size_t x;
        size_t y;
    } coordinates_t;

    /**
     * @struct s_resources
     *
     * This structure represents the resources on a tile on the map.
     * Each tile has a quantity of food,
     * linemate, deraumere, sibur, mendiane, phiras, and thystame.
     */
    typedef struct resources_s {
        hashmap_t *resources;
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
        size_t width;
        size_t height;
        array_t *tiles;
    } map_t;

    /**
     * @brief Init a new map.
     *
     * @param width The width of the map.
     * @param height The height of the map.
     * @return The new map.
     */
    map_t *init_map(size_t width, size_t height);

    /**
     * @brief deslete a map.
     *
     * @param map The map to free.
     */
    void destroy_map(map_t *map);

    /**
     * @brief Get a tile from the map.
     *
     * @param map The map.
     * @param x The x coordinate of the tile.
     * @param y The y coordinate of the tile.
     * @return The tile.
     */
    tile_t *get_tile(map_t *map, size_t x, size_t y);

    /**
     * @brief Get a tile from the map.
     *
     * @param map The map.
     * @param coordinates The coordinates of the tile.
     * @return The tile.
     */
    tile_t *get_tile_by_coordinates(map_t *map, coordinates_t coordinates);

    /**
     * @brief Init a new tile.
     *
     * @param x The x coordinate of the tile.
     * @param y The y coordinate of the tile.
     * @return The new tile.
     */
    tile_t *init_tile(size_t x, size_t y);

    /**
     * @brief Destroy a tile.
     *
     * @param tile The tile to destroy.
     */
    void destroy_tile(tile_t *tile);

    /**
     * @brief Return a string with the tile informations.
     *
     * @param tile The tile.
     * @return The string.
     */
    char *tile_to_string(tile_t *tile);

    /**
     * @brief Return a string with the map informations.
     *
     * @param map The map.
     * @return The string.
     */
    char *map_to_string(map_t *map);

    /**
     * @brief Return a string with the map dimensions.
     *
     * @param map The map.
     * @return The string.
     */
    char *map_dimensions_to_string(map_t *map);

    /**
     * @brief Generate ressources on the map for one tick.
     *
     * @param map The map.
     */
    void generate_ressources(map_t *map);

    /**
     * @brief Init the resources of a tile.
     *
     * @return The resources.
     */
    resources_t init_resources(void);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_MAP_H
