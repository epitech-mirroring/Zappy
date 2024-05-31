/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** different useful functions that are copy from c++
*/

#ifndef ARRAY_H
    #define ARRAY_H

    #include <stdlib.h>

    typedef struct array_s {
        void (*element_destructor)(void *element);
        void (*destructor)(struct array_s *array);
        void (*clear)(struct array_s *array);
        void (*push_back)(struct array_s *array, void *element);
        void (*remove)(struct array_s *array, size_t index);
        void (*insert)(struct array_s *array, void *element, int index);
        void *(*get_at)(struct array_s *array, int index);
        size_t (*get_size)(struct array_s *array);
        void *(*set_at)(struct array_s *array, int index, void *element);

        void **array;
        size_t elementSize;
    } array_t;

    void array_push_back(array_t *array, void *element);
    void array_remove(array_t *array, size_t index);
    void array_insert(array_t *array, void *element, int index);
    void array_clear(array_t *array);
    void array_get_at(array_t *array, size_t index);
    size_t array_get_size(array_t *array);
    void array_resize(array_t *array, size_t newSize);
    void array_set_at(array_t *array, int index, void *element);
    void array_destructor(array_t *array);
    array_t *array_constructor(size_t elementSize,
        void(*element_destructor)(void *element));

#endif
