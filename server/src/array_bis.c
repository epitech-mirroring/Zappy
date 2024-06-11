/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** different useful functions that are copy from c++
*/

#include "array.h"

void array_push_back(array_t *array, void *element)
{
    array->data = realloc(array->data,
        array->elementSize * (array_get_size(array) + 1));
    array->data[array_get_size(array)] = element;
    array->data[array_get_size(array) + 1] = NULL;
}

void array_remove(array_t *array, size_t index)
{
    void *tmp = array->data[index];

    for (int i = index; i < array_get_size(array) - 1; i++)
        array->data[i] = array->data[i + 1];
    array->data[array_get_size(array)] = NULL;
    array->data = realloc(array->data, array->elementSize
        * (array_get_size(array)));
    array->element_destructor(tmp);
}

void array_insert(array_t *array, void *element, int index)
{
    array->data = realloc(array->data,
        array->elementSize * (array_get_size(array) + 1));
    array->data[array_get_size(array) + 1] = NULL;
    for (int i = array_get_size(array); i > index; i--)
        array->data[i] = array->data[i - 1];
    array->data[index] = element;
}

void array_clear(array_t *array)
{
    for (int i = 0; i < array_get_size(array); i++)
        array->element_destructor(array->data[i]);
    free(array->data);
    array->data = NULL;
}

void array_get_at(array_t *array, size_t index)
{
    if (index >= array_get_size(array))
        return NULL;
    return array->data[index];
}
