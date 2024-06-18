
/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "hashmap.h"

hashmap_t *create_hashmap(void)
{
    hashmap_t *hashmap = malloc(sizeof(hashmap_t));

    hashmap->size = 0;
    hashmap->buckets = malloc(sizeof(bucket_t *) * 100);
    for (int i = 0; i < 100; i++)
        hashmap->buckets[i] = NULL;
    return hashmap;
}

int hashcode(char *key)
{
    int hash = 0;

    for (int i = 0; i < my_strlen(key); i++)
        hash += key[i];
    return hash % 100;
}

void hashmap_put(hashmap_t *map, char *key, void *data)
{
    int hash = hashcode(key);
    bucket_t *bucket = malloc(sizeof(bucket_t));

    bucket->key = key;
    bucket->data = data;
    bucket->next = map->buckets[hash];
    map->buckets[hash] = bucket;
    map->size++;
}

void *hashmap_get(hashmap_t *map, char *key)
{
    int hash = hashcode(key);
    bucket_t *bucket = map->buckets[hash];

    while (bucket != NULL) {
        if (my_strcmp(bucket->key, key) == 0)
            return bucket->data;
        bucket = bucket->next;
    }
    return NULL;
}

void hashmap_remove(hashmap_t *map, char *key)
{
    int hash = hashcode(key);
    bucket_t *bucket = map->buckets[hash];
    bucket_t *prev = NULL;

    while (bucket != NULL) {
        if (my_strcmp(bucket->key, key) == 0) {
            prev == NULL ? (map->buckets[hash] = bucket->next)
            : (prev->next = bucket->next);
            map->size--;
            free(bucket);
            return;
        }
        prev = bucket;
        bucket = bucket->next;
    }
}
