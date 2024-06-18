/*
** EPITECH PROJECT, 2022
** my-libs
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ZAPPY_HASHMAP_H
    #define ZAPPY_HASHMAP_H
    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>

    /**
     * @brief Structure of the elements in the hashmap
     *
     * This structure represents the elements in the hashmap.
     * Each element has a key and a data.
     * The key is a string and the data is a void pointer.
     * The next element is a pointer to the next element in the bucket.
     */
    typedef struct bucket {
        char *key;
        void *data;
        struct bucket *next;
    } bucket_t;

    /**
     * @brief Function to create a new bucket
     *
     * This function creates a new bucket.
     * The bucket is initialized with a key and a data.
     * @param key The key of the bucket
     * @param data The data of the bucket
     * @return bucket_t* The new bucket
     */
    bucket_t *create_bucket(char *key, void *data);

    /**
     * @brief Function to destroy a bucket
     *
     * This function destroys a bucket.
     * The bucket is freed from memory.
     * @param bucket The bucket
     */
    void destroy_bucket(bucket_t *bucket);

    /**
     * @brief Structure of the hashmap
     *
     * This structure represents the hashmap.
     * The hashmap has a size and an array of buckets.
     */
    typedef struct hashmap {
        int size;
        bucket_t **buckets;
    } hashmap_t;

    /**
     * @brief Function to create a new hashmap
     *
     * This function creates a new hashmap.
     * The hashmap is initialized with a size of 100.
     * @return hashmap_t* The new hashmap
     */
    hashmap_t *create_hashmap(void);

    /**
     * @brief Function to destroy a hashmap
     *
     * This function destroys a hashmap.
     * The hashmap is freed from memory.
     * @param map The hashmap
     */
    void destroy_hashmap(hashmap_t *map);

    /**
     * @brief Function to create a new bucket
     *
     * This function creates a new bucket.
     * The bucket is initialized with a key and a data.
     * @param key The key of the bucket
     * @param data The data of the bucket
     * @return bucket_t* The new bucket
     */
    int hashcode(char *key);

    /**
     * @brief Function to put an element in the hashmap
     *
     * This function puts an element in the hashmap.
     * The element has a key and a data.
     * @param map The hashmap
     * @param key The key of the element
     * @param data The data of the element
     */
    void hashmap_put(hashmap_t *map, char *key, void *data);

    /**
     * @brief Function to get an element from the hashmap
     *
     * This function gets an element from the hashmap.
     * The element has a key.
     * @param map The hashmap
     * @param key The key of the element
     * @return void* The data of the element
     */
    void *hashmap_get(hashmap_t *map, char *key);

    /**
     * @brief Function to remove an element from the hashmap
     *
     * This function removes an element from the hashmap.
     * The element has a key.
     * @param map The hashmap
     * @param key The key of the element
     */
    void hashmap_remove(hashmap_t *map, char *key);

    /**
     * @brief Function to check if the hashmap contains an element
     *
     * This function checks if the hashmap contains an element.
     * The element has a key.
     * @param map The hashmap
     * @param key The key of the element
     * @return bool True if the hashmap contains the element, false otherwise
     */
    bool hashmap_contains(hashmap_t *map, char *key);

    /**
     * @brief Function to check if the hashmap is empty
     *
     * This function checks if the hashmap is empty.
     * @param map The hashmap
     * @return bool True if the hashmap is empty, false otherwise
     */
    bool is_hashmap_empty(hashmap_t *map);

    /**
     * @brief Function to get the size of the hashmap
     *
     * This function gets the size of the hashmap.
     * @param map The hashmap
     * @return int The size of the hashmap
     */
    char **hashmap_to_array(hashmap_t *map);

    #ifdef __cplusplus
}
    #endif // __cplusplus
#endif //ZAPPY_HASHMAP_H
