/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests for array.c
*/

#include <gtest/gtest.h>
#include "array.h"

TEST(ArrayTests, test_array_create)
{
    array_t *array = array_constructor(sizeof(char), &free);
    ASSERT_EQ(array->data, nullptr);
    ASSERT_EQ(array->elementSize, sizeof(char));
    ASSERT_EQ(array->element_destructor, &free);
}

TEST(ArrayTests, test_array_without_destructor)
{
    array_t *array = array_constructor(sizeof(char), NULL);

    ASSERT_EQ(array->data, nullptr);
    ASSERT_EQ(array->elementSize, sizeof(char));
    ASSERT_EQ(array->element_destructor, nullptr);
}

TEST(ArrayTests, test_array_push_back)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->elementSize, sizeof(char));
    ASSERT_EQ(array->element_destructor, &free);
}

TEST(ArrayTests, test_array_remove)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    array_remove(array, 0);
    ASSERT_EQ(array->data[0], nullptr);
}

TEST(ArrayTests, test_array_remove_with_multiples_elements)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");
    char *element2 = strdup("World!");

    array_push_back(array, element);
    array_push_back(array, element2);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], element2);
    array_remove(array, 0);
    ASSERT_EQ(array->data[0], element2);
    ASSERT_EQ(array->data[1], nullptr);
}

TEST(ArrayTests, test_array_insert)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_insert(array, element, 0);
    ASSERT_EQ(array->data[0], element);
}

TEST(ArrayTests, test_array_insert_with_multiples_elements)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");
    char *element2 = strdup("World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], nullptr);
    array_insert(array, element2, 1);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], element2);
}

TEST(ArrayTests, test_array_clear)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_clear(array);
    ASSERT_EQ(array->data[0], nullptr);
}

TEST(ArrayTests, test_array_get_at)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    ASSERT_EQ(array_get_at(array, 0), nullptr);
    array_push_back(array, element);
    ASSERT_EQ(array_get_at(array, 0), element);
}

TEST(ArrayTests, test_array_get_size)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    ASSERT_EQ(array_get_size(array), 0);
    array_push_back(array, element);
    ASSERT_EQ(array_get_size(array), 1);
}

TEST(ArrayTests, test_array_resize)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->elementSize, sizeof(char));
    ASSERT_EQ(array->element_destructor, &free);
    array_resize(array, 2);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->elementSize, sizeof(char));
    ASSERT_EQ(array->element_destructor, &free);
}

TEST(ArrayTests, test_array_resize_with_less_elements)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");
    char *element2 = strdup("World!");

    array_push_back(array, element);
    array_push_back(array, element2);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], element2);
    array_resize(array, 1);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], nullptr);
}

TEST(ArrayTests, test_array_resize_with_more_elements)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_resize(array, 2);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], nullptr);
}

TEST(ArrayTests, test_array_set_at)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");
    char *element2 = strdup("World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_set_at(array, 0, element2);
    ASSERT_EQ(array->data[0], element2);
}

TEST(ArrayTests, test_array_set_at_with_index_out_of_range)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");
    char *element2 = strdup("World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_set_at(array, 1, element2);
    ASSERT_EQ(array->data[0], element);
    ASSERT_EQ(array->data[1], nullptr);
}

TEST(ArrayTests, test_array_destructor)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_destructor(array);
}

TEST(ArrayTests, test_array_destructor_with_null_data)
{
    array_t *array = array_constructor(sizeof(char), &free);

    array_destructor(array);
}

TEST(ArrayTests, test_array_destructor_with_null_destructor)
{
    array_t *array = array_constructor(sizeof(char), NULL);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_destructor(array);
}

TEST(ArrayTests, test_array_get_size_with_null_data)
{
    array_t *array = array_constructor(sizeof(char), &free);

    ASSERT_EQ(array_get_size(array), 0);
}

TEST(ArrayTests, test_array_set_at_with_null_data)
{
    array_t *array = array_constructor(sizeof(char), &free);
    char *element = strdup("Hello, World!");

    array_push_back(array, element);
    ASSERT_EQ(array->data[0], element);
    array_set_at(array, 0, nullptr);
    ASSERT_EQ(array->data[0], nullptr);
}

TEST(ArrayTests, test_array_destructor_with_null_array)
{
    array_t *array = nullptr;

    array_destructor(array);
}
