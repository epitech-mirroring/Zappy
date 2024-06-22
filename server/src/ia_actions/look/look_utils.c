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

static char *make_string_for_elements(const int elements[8])
{
    char *str = calloc(1024, sizeof(char));
    char *tmp = calloc(1024, sizeof(char));
    const char *element_str[8] = {"player", "food", "linemate", "deraumere",
        "sibur", "mendiane", "phiras", "thystame"};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < elements[i]; j++) {
            sprintf(str, "%s%s", tmp, element_str[i]);
            tmp = add_space(str, tmp, j, elements[i]);
        }
    }
    free(str);
    return tmp;
}

char *get_element_on_tile(tile_t *tile)
{
    int elements[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    elements[1] = hashmap_get(tile->resources, "food");
    elements[2] = hashmap_get(tile->resources, "linemate");
    elements[3] = hashmap_get(tile->resources, "deraumere");
    elements[4] = hashmap_get(tile->resources, "sibur");
    elements[5] = hashmap_get(tile->resources, "mendiane");
    elements[6] = hashmap_get(tile->resources, "phiras");
    elements[7] = hashmap_get(tile->resources, "thystame");
    return make_string_for_elements(elements);
}
