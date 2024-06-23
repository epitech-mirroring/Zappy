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
    char *tmp = calloc(2048, sizeof(char));

    if (element == NULL || message == NULL)
        return message;
    for (int i = 0; i < count; i++) {
        sprintf(tmp, "%s", message);
        if (strlen(message) == 0)
            sprintf(message, "%s", element);
        else
            sprintf(message, "%s %s", tmp, element);
    }
    free(tmp);
    return message;
}

static char *make_string_for_elements(hashmap_t *elements)
{
    char *tmp = calloc(2048, sizeof(char));
    char *element_str[10] = {"egg", "player", "food", "linemate", "deraumere",
        "sibur", "mendiane", "phiras", "thystame", NULL};
    int count = 0;

    if (is_hashmap_empty(elements) == true)
        return NULL;
    for (int i = 0; i < 8; i++) {
        if (hashmap_contains(elements, element_str[i]) == false)
            hashmap_put(elements, element_str[i], 0);
        count = hashmap_get(elements, element_str[i]);
        if (count > 0){
            tmp = make_string(element_str[i], tmp, count);
        }
    }
    return tmp;
}

char *get_element_on_tile(tile_t *tile, hashmap_t *content)
{
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
