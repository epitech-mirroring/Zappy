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

size_t array_get_size(array_t *array)
{
    size_t size = 0;

    if (array->data == NULL)
        return 0;
    while (array->data[size] != NULL)
        size++;
    return size;
}

void array_set_at(array_t *array, int index, void *element)
{
    if (index >= array_get_size(array))
        return;
    array->element_destructor(array->data[index]);
    array->data[index] = element;
}

void array_destructor(array_t *array)
{
    array_clear(array);
    free(array->data);
    free(array);
}

void array_resize(array_t *array, size_t newSize)
{
    if (newSize < array_get_size(array))
        for (int i = newSize; i < array_get_size(array); i++)
            array->element_destructor(array->data[i]);
    array->data = realloc(array->data, array->elementSize * (newSize + 1));
    array->data[newSize] = NULL;
}

array_t *array_constructor(size_t elementSize,
    void(*element_destructor)(void *element))
{
    array_t *array = malloc(sizeof(array_t));
    //TODO: refactor this
    array->element_destructor = element_destructor; //to be refacto
    array->data = malloc(elementSize);
    array->elementSize = elementSize;
    return array;
}
