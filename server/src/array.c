/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** different useful functions that are copy from c++
*/

#include "array.h"

size_t array_get_size(array_t *array)
{
    size_t size = 0;

    if (array == NULL || array->data == NULL)
        return 0;
    while (array->data[size] != NULL)
        size++;
    return size;
}

void array_set_at(array_t *array, int index, void *element)
{
    if (array == NULL || index >= array_get_size(array))
        return;
    array->element_destructor(array->data[index]);
    array->data[index] = element;
}

void array_destructor(array_t *array)
{
    size_t size = 0;

    if (array == NULL)
        return;
    size = array_get_size(array);
    for (size_t i = 0; i < size; i++) {
        if (array->element_destructor != NULL)
            array->element_destructor(array->data[i]);
    }
    free(array->data);
    free(array);
}

void array_resize(array_t *array, size_t newSize)
{
    void **tmp = calloc(newSize + 1, array->elementSize);

    if (array == NULL) {
        free(tmp);
        return;
    }
    for (int i = 0; i < newSize; i++) {
        if (i < array_get_size(array))
            tmp[i] = array->data[i];
        else
            array->element_destructor(array->data[i]);
    }
    free(array->data);
    array->data = tmp;
}

array_t *array_constructor(size_t elementSize,
    void(*element_destructor)(void *element))
{
    array_t *array = malloc(sizeof(array_t));

    array->element_destructor = element_destructor;
    array->data = NULL;
    array->elementSize = elementSize;
    return array;
}
