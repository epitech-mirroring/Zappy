/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** different useful functions that are copy from c++
*/

#include "array.h"

void array_push_back(array_t *array, void *element)
{
    array->array = realloc(array->array, array->elementSize
        * (array->get_size(array) + 1));
    array->array[array->get_size(array) - 1] = element;
    array->array[array->get_size(array)] = NULL;
}

void array_remove(array_t *array, size_t index)
{
    void *tmp = array->array[index];

    for (int i = index; i < array->get_size(array) - 1; i++)
        array->array[i] = array->array[i + 1];
    array->array[array->get_size(array)] = NULL;
    array->array = realloc(array->array, array->elementSize
        * (array->get_size(array)));
    array->element_destructor(tmp);
}

void array_insert(array_t *array, void *element, int index)
{
    array->array = realloc(array->array,
        array->elementSize * (array->get_size(array) + 1));
    array->array[array->get_size(array) + 1] = NULL;
    for (int i = array->get_size(array); i > index; i--)
        array->array[i] = array->array[i - 1];
    array->array[index] = element;
}

void array_clear(array_t *array)
{
    for (int i = 0; i < array->get_size(array); i++)
        array->element_destructor(array->array[i]);
    free(array->array);
    array->array = NULL;
}

void array_get_at(array_t *array, size_t index)
{
    if (index >= array->get_size(array))
        return NULL;
    return array->array[index];
}

size_t array_get_size(array_t *array)
{
    size_t size = 0;

    if (array->array == NULL)
        return 0;
    while (array->array[size] != NULL)
        size++;
    return size;
}

void array_set_at(array_t *array, int index, void *element)
{
    if (index >= array->get_size(array))
        return;
    array->element_destructor(array->array[index]);
    array->array[index] = element;
}

void array_destructor(array_t *array)
{
    array->clear(array);
    free(array->array);
    free(array);
}

void array_resize(array_t *array, size_t newSize)
{
    if (newSize < array->get_size(array))
        for (int i = newSize; i < array->get_size(array); i++)
            array->element_destructor(array->array[i]);
    array->array = realloc(array->array, array->elementSize * (newSize + 1));
    array->array[newSize] = NULL;
}

array_t *array_constructor(size_t elementSize,
    void(*element_destructor)(void *element))
{
    array_t *array = malloc(sizeof(array_t));

    array->element_destructor = element_destructor;
    array->destructor = array_destructor;
    array->clear = array_clear;
    array->push_back = array_push_back;
    array->remove = array_remove;
    array->insert = array_insert;
    array->get_at = array_get_at;
    array->get_size = array_get_size;
    array->set_at = array_set_at;
    array->array = malloc(elementSize);
    array->elementSize = elementSize;
    return array;
}
