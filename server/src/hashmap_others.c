/*
** EPITECH PROJECT, 2023
** mini_shell1
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "hashmap.h"
#include <string.h>

bool hashmap_contains(hashmap_t *map, char *key)
{
    int hash = hashcode(key);
    bucket_t *bucket = map->buckets[hash];

    while (bucket != NULL) {
        if (strcmp(bucket->key, key) == 0)
            return true;
        bucket = bucket->next;
    }
    return false;
}

bool is_hashmap_empty(hashmap_t *map)
{
    return map->size == 0;
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

void hashmap_set(hashmap_t *map, char *key, int data)
{
    int hash = hashcode(key);
    bucket_t *bucket = map->buckets[hash];

    if (bucket == NULL)
        return;
    while (bucket->next != NULL) {
        if (strcmp(bucket->key, key) == 0) {
            break;
        }
        bucket = bucket->next;
    }
    if (strcmp(bucket->key, key) == 0) {
        bucket->data = data;
        return;
    }
}
