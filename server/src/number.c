/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** C file for infinite number
*/

#include "number.h"
#include <stdlib.h>
#include <string.h>

number_t *create_number_with_int(int number)
{
    number_t *new_number = malloc(sizeof(number_t));
    int size = 0;

    if (!new_number)
        return NULL;
    for (int tmp = number; tmp != 0; tmp /= 10)
        size++;
    new_number->number = calloc((size + 1), sizeof(char));
    for (; number != 0;) {
        new_number->number[size - 1] = number % 10 + '0';
        number /= 10;
        size--;
    }
    return new_number;
}

number_t *create_number_with_string(char *number)
{
    number_t *new_number = malloc(sizeof(number_t));

    if (!new_number)
        return NULL;
    new_number->number = number;
    return new_number;
}

void destroy_number(number_t *number)
{
    free(number->number);
    free(number);
}

void add_numbers(number_t *number1, number_t *number2)
{
    int size1 = get_size_of_number(number1);
    int size2 = get_size_of_number(number2);
    char *new_number = NULL;
    int size = 0;
    int carry = 0;

    size = size1 > size2 ? size1 : size2;
    if (size1 / (10 * (size1 - 1)) + size2 / (10 * (size2 - 1)) >= 10)
        size++;
    new_number = calloc((size + 1), sizeof(char));
    for (int i = size - 1; i != 0; i--) {
        new_number[i] = (number1->number[i] - '0')
            + (number2->number[i] - '0') + carry;
        carry = new_number[i] / 10;
        new_number[i] %= 10;
    }
    new_number[0] = carry;
    free(number1->number);
    number1->number = new_number;
}

void subtract_numbers(number_t *number1, number_t *number2)
{
    int size1 = get_size_of_number(number1);
    int size2 = get_size_of_number(number2);
    char *new_number = NULL;
    int size = 0;
    int carry = 0;

    size = size1 > size2 ? size1 : size2;
    if (size1 / (10 * (size1 - 1)) + size2 / (10 * (size2 - 1)) >= 10)
        size++;
    new_number = calloc((size + 1), sizeof(char));
    for (int i = size - 1; i != 0; i--) {
        new_number[i] = (number1->number[i] - '0')
            - (number2->number[i] - '0') + carry;
        carry = new_number[i] >= 0 ? 0 : -1;
        new_number[i] %= 10;
        new_number[i] = carry == -1 ? new_number[i] + 10 : new_number[i];
    }
    new_number[0] = carry;
    free(number1->number);
    number1->number = new_number;
}

void add_int_to_number(number_t *number, int nb)
{
    number_t *new_number = create_number_with_int(nb);

    add_numbers(number, new_number);
    destroy_number(new_number);
}

void subtract_int_to_number(number_t *number, int nb)
{
    number_t *new_number = create_number_with_int(nb);

    subtract_numbers(number, new_number);
    destroy_number(new_number);
}

int compare_int_to_number(number_t *number, int nb)
{
    number_t *new_number = create_number_with_int(nb);
    int res = strcmp(number->number, new_number->number);

    destroy_number(new_number);
    return res;
}

int get_size_of_int(int number)
{
    int size = 0;

    for (int tmp = number; tmp != 0; tmp /= 10)
        size++;
    return size;
}
