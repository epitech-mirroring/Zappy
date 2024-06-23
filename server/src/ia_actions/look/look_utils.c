/*
** EPITECH PROJECT, 2024
** Project
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ia_actions/look.h"

static char *make_string(char *element, char *message, int count)
{
    if (element == NULL || message == NULL)
        return message;
    for (int i = 0; i < count; i++) {
        if (strlen(message) == 0)
            sprintf(message, "%s", element);
        else
            sprintf(message, "%s %s", message, element);
    }
    return message;
}

static char *make_string_for_elements(hashmap_t *elements)
{
    char *tmp = calloc(1024, sizeof(char));
    char *element_str[9] = {"player", "food", "linemate", "deraumere",
                                  "sibur", "mendiane", "phiras", "thystame", NULL};
    int count = 0;

    for (int i = 0; i < 8; i++) {
        if (hashmap_get(elements, element_str[i]) > 0){
            count = hashmap_get(elements, element_str[i]);
            tmp = make_string(element_str[i], tmp, count);
        }
    }
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
