/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ia_actions/look.h"

static bool is_tile_in_array(tile_t *tile, array_t *tiles)
{
    for (size_t i = 0; i < array_get_size(tiles); i++) {
            if (tile == array_get_at(tiles, i)) {
                    return true;
                }
        }
    return false;
}

static size_t get_elements_size(const int *elements)
{
    size_t size = 0;
    const int element_size[8] = {6, 4, 8, 9, 5, 8, 6, 8};

    for (int i = 0; i < 8; i++) {
            size += elements[i] * element_size[i] +
                    (i * elements[i] - i == 0 ? 0 : 1);
        }
    return size;
}

static char *make_string_for_elements(const int *elements)
{
    size_t size = get_elements_size(elements);
    char *str = calloc(size + 1, sizeof(char));
    const char *element_str[8] = {"player", "food", "linemate", "deraumere",
                                  "sibur", "mendiane", "phiras", "thystame"};

    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < elements[i]; j++) {
                    strcat(str, element_str[i]);
                    if (j < elements[i] - 1)
                        strcat(str, " ");
                }
            strcat(str, ",");
        }
    return str;
}

char *get_element_on_tile(game_t *game, array_t **tiles,
                                 size_t x, size_t y)
{
    size_t index = (y * game->map->width) + x;
    tile_t *tile = array_get_at(*tiles, index);
    int elements[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    if ((is_tile_in_array(tile, *tiles)) == true) {
            array_push_back(*tiles, tile);
            return ",";
        }
    elements[0] = tile->player_count;
    elements[1] = hashmap_get(tile->resources, "food");
    elements[2] = hashmap_get(tile->resources, "linemate");
    elements[3] = hashmap_get(tile->resources, "deraumere");
    elements[4] = hashmap_get(tile->resources, "sibur");
    elements[5] = hashmap_get(tile->resources, "mendiane");
    elements[6] = hashmap_get(tile->resources, "phiras");
    elements[7] = hashmap_get(tile->resources, "thystame");
    array_push_back(*tiles, tile);
    return make_string_for_elements(elements);
}
