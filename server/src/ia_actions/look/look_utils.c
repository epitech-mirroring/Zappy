/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ia_actions/look.h"

static char *add_space(char *str, char *tmp, int j, int element)
{
    if (j < element - 1)
        sprintf(tmp, "%s ", str);
    return tmp;
}

static char *make_string_for_elements(hashmap_t *element)
{
    char *str = calloc(1024, sizeof(char));
    char *tmp = calloc(1024, sizeof(char));
    const char *element_str[8] = {"player", "food", "linemate", "deraumere",
        "sibur", "mendiane", "phiras", "thystame"};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < hashmap_get(element, element_str[i]); j++) {
            sprintf(str, "%s%s", tmp, element_str[i]);
            tmp = add_space(str, tmp, j, hashmap_get(element, element_str[i]));
        }
    }
    free(str);
    return tmp;
}

static hashmap_t *init_tile_content(void)
{
    hashmap_t *resources;

    resources = create_hashmap();
    hashmap_put(resources, "player", 0);
    hashmap_put(resources, "food", 0);
    hashmap_put(resources, "linemate", 0);
    hashmap_put(resources, "deraumere", 0);
    hashmap_put(resources, "sibur", 0);
    hashmap_put(resources, "mendiane", 0);
    hashmap_put(resources, "phiras", 0);
    hashmap_put(resources, "thystame", 0);
    return resources;
}

char *get_element_on_tile(tile_t *tile)
{
    hashmap_t *content = init_tile_content();

    hashmap_set(content, "player", tile->player_count);
    hashmap_set(content, "food", hashmap_get(tile->resources, "food"));
    hashmap_set(content, "linemate", hashmap_get(tile->resources, "linemate"));
    hashmap_set(content, "deraumere",
        hashmap_get(tile->resources, "deraumere"));
    hashmap_set(content, "sibur", hashmap_get(tile->resources, "sibur"));
    hashmap_set(content, "mendiane", hashmap_get(tile->resources, "mendiane"));
    hashmap_set(content, "phiras", hashmap_get(tile->resources, "phiras"));
    hashmap_set(content, "thystame", hashmap_get(tile->resources, "thystame"));

    return make_string_for_elements(content);
}
