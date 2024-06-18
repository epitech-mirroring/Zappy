
/*
** EPITECH PROJECT, 2023
** mini_shell1
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/


#include "hashmap.h"

bool hashmap_contains(hashmap_t *map, char *key)
{
    int hash = hashcode(key);
    bucket_t *bucket = map->buckets[hash];
    while (bucket != NULL) {
        if (my_strcmp(bucket->key, key) == 0)
            return true;
        bucket = bucket->next;
    }
    return false;
}

bool is_hashmap_empty(hashmap_t *map)
{
    return map->size == 0;
}

char **hashmap_to_array(hashmap_t *map)
{
    char **array = malloc(sizeof(char *) * (map->size + 1));
    int i = 0;
    for (int j = 0; j < 100; j++) {
        bucket_t *bucket = map->buckets[j];
        while (bucket != NULL) {
            char *key = malloc(sizeof(char) * (my_strlen(bucket->key) + 1));
            char *data = malloc(sizeof(char) * (my_strlen(bucket->data) + 1));
            my_strcpy(key, bucket->key);
            my_strcpy(data, bucket->data);
            char *str = malloc(my_strlen(key) + my_strlen(data) + 2);
            my_strcpy(str, key);
            my_strcat(str, "=");
            my_strcat(str, data);
            array[i] = str;
            i++;
            bucket = bucket->next;
        }
    }
    array[i] = NULL;
    return array;
}

void destroy_hashmap(hashmap_t *map)
{
    bucket_t *next = NULL;
    bucket_t *bucket = NULL;

    for (int i = 0; i < 100; i++) {
        bucket = map->buckets[i];
        while (bucket != NULL) {
            next = bucket->next;
            destroy_bucket(bucket);
            bucket = next;
        }
    }
    free(map->buckets);
    free(map);
}
