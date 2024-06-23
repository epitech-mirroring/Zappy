/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** different useful functions that are copy from c++
*/

#include "array.h"

void array_push_back(array_t *array, void *element)
{
    void **tmp = calloc(array_get_size(array) + 2, array->elementSize);
    size_t size = array_get_size(array);

    for (size_t i = 0; i < size; i++)
        tmp[i] = array->data[i];
    tmp[size] = element;
    tmp[size + 1] = NULL;
    free(array->data);
    array->data = tmp;
}

void array_remove(array_t *array, size_t index)
{
    size_t size = array_get_size(array);
    void **tmp_data = calloc(size, array->elementSize);
    int j = 0;

    for (size_t i = 0; i < size; i++) {
        if (i != index) {
            tmp_data[j] = array->data[i];
            j++;
        }
    }
    free(array->data);
    array->data = tmp_data;
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
    size_t size = array_get_size(array);

    if (array->element_destructor != NULL)
        for (size_t i = 0; i < size; i++) {
            array->element_destructor(array->data[i]);
        }
    free(array->data);
    array->data = calloc(1, array->elementSize);
}

void *array_get_at(array_t *array, size_t index)
{
    if (index >= array_get_size(array))
        return NULL;
    return array->data[index];
}
