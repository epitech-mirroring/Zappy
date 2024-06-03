/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** different useful functions that are copy from c++
*/

#ifndef ARRAY_H
    #define ARRAY_H

    #include <stdlib.h>

    /**
     * @struct array_s this structure represents an array in C
     *
     * This structure represents an array in C.
     * Each array has a pointer to the array,
     * the size of the elements in the array, and functions to manipulate the array.
     */
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

    /**
     * @brief Pushes an element to the back of the array
     *
     * @param array the array to push the element to
     * @param element the element to push to the array
     */
    void array_push_back(array_t *array, void *element);

    /**
     * @brief Removes an element from the array
     *
     * @param array the array to remove the element from
     * @param index the index of the element to remove
     */
    void array_remove(array_t *array, size_t index);

    /**
     * @brief Inserts an element into the array
     *
     * @param array the array to insert the element into
     * @param element the element to insert
     * @param index the index to insert the element at
     */
    void array_insert(array_t *array, void *element, int index);

    /**
     * @brief Clears the array
     *
     * @param array the array to clear
     */
    void array_clear(array_t *array);

    /**
     * @brief Gets an element at an index
     *
     * @param array the array to get the element from
     * @param index the index to get the element from
     */
    void array_get_at(array_t *array, size_t index);

    /**
     * @brief Gets the size of the array
     *
     * @param array the array to get the size of
     */
    size_t array_get_size(array_t *array);

    /**
     * @brief Resizes the array
     *
     * @param array the array to resize
     * @param newSize the new size of the array
     */
    void array_resize(array_t *array, size_t newSize);

    /**
     * @brief Sets an element at an index
     *
     * @param array the array to set the element in
     * @param index the index to set the element at
     * @param element the element to set
     */
    void array_set_at(array_t *array, int index, void *element);

    /**
     * @brief Destroys the array
     *
     * @param array the array to destroy
     */
    void array_destructor(array_t *array);

    /**
     * @brief Constructs an array
     *
     * @param elementSize the size of the elements in the array
     * @param element_destructor the destructor for the elements in the array
     */
    array_t *array_constructor(size_t elementSize,
        void(*element_destructor)(void *element));

#endif
