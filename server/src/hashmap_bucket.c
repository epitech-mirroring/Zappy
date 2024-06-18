/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "hashmap.h"

bucket_t *create_bucket(char *key, int data)
{
    bucket_t *bucket = malloc(sizeof(bucket_t));

    if (bucket == NULL)
        return NULL;
    bucket->key = key;
    bucket->data = data;
    bucket->next = NULL;
    return bucket;
}

void destroy_bucket(bucket_t *bucket)
{
    free(bucket->key);
    free(bucket);
}
