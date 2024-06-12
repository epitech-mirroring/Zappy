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
    new_number = calloc((size + 1), sizeof(char));
    for (; number != 0;) {
        new_number[size - 1] = number % 10;
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
    new_number = number;
    return new_number;
}

void destroy_number(number_t *number)
{
    free(number->number);
    free(number);
}

static number_t *remove_simb(number_t *number)
{
    number_t *new_number = malloc(sizeof(number_t));
    int size = strlen(number->number) - 1;

    if (!new_number)
        return NULL;
    new_number = calloc((size + 1), sizeof(char));
    for (int i = 1; i <= size; i++)
        new_number[i - 1] = number->number[i];
    return new_number;
}

static int get_size_of_number(number_t *number)
{
    int size = strlen(number->number);

    if (number->number[0] < 0 || number->number[0] > 9)
        size--;
    return strlen(number->number);
}

static void add_numbers_sign(number_t *number1,
    number_t *number2, char *new_number, size_t size)
{
    if (number1->number[0] == '-' || number2->number[0] == '-') {
        new_number = calloc((size + 3), sizeof(char));
        new_number[0] = '-';
    } else {
        new_number = calloc((size + 2), sizeof(char));
    }
}

void add_numbers(number_t *number1, number_t *number2)
{
    int size1 = get_size_of_number(number1);
    int size2 = get_size_of_number(number2);
    char *new_number = NULL;
    int size = 0;
    int carry = 0;
    int i;

    size = size1 > size2 ? size1 : size2;
    add_numbers_sign(number1, number2, new_number, size);
    for (i = size; i != 0 && new_number[i - 1] != '-'; i--) {
        new_number[i] = (number1->number[i])
            + (number2->number[i]) + carry;
        carry = new_number[i] / 10;
        new_number[i] %= 10;
    }
    new_number[i] = carry;
    free(number1->number);
    number1->number = new_number;
}

void subtract_numbers(number_t *number1, number_t *number2)
{
    int size1 = get_size_of_number(number1);
    int size2 = get_size_of_number(number2);
    char *new_number = NULL;
    int size = size1 > size2 ? size1 : size2;
    int carry = 0;

    if (size1 / (10 * (size1 - 1)) - size2 / (10 * (size2 - 1)) < 0)
        size++;
    new_number = calloc((size + 1), sizeof(char));
    for (int i = size - 1; i != 0; i--) {
        new_number[i] = (number1->number[i])
            - (number2->number[i]) + carry;
        carry = new_number[i] >= 0 ? 0 : -1;
        new_number[i] = carry == -1 ? new_number[i]
            % 10 + 10 : new_number[i] % 10;
    }
    new_number[0] = carry ;
    free(number1->number);
    number1->number = new_number;
}

void calcul(number_t *number1, number_t *number2, operation_e operation)
{
    number_t *tmp;

    if (operation == ADD) {
        if (number2->number[0] == '-') {
            tmp = remove_simb(number2);
            subtract_numbers(number1, tmp);
            destroy_number(tmp);
        } else {
            add_numbers(number1, number2);
        }
        add_numbers(number1, number2);
    } else {
        if (number2->number[0] == '-') {
            tmp = remove_simb(number2);
            add_numbers(number1, tmp);
            destroy_number(tmp);
        } else {
            subtract_numbers(number1, number2);
        }
    }
}

void add_int_to_number(number_t *number, int nb)
{
    number_t *new_number = create_number_with_int(nb);

    calcul(number, new_number, ADD);
    destroy_number(new_number);
}

void subtract_int_to_number(number_t *number, int nb)
{
    number_t *new_number = create_number_with_int(nb);

    calcul(number, new_number, SUBTRACT);
    destroy_number(new_number);
}

int compare_int_to_number(number_t *number, int nb)
{
    number_t *new_number = create_number_with_int(nb);
    int res = strcmp(number->number, new_number);

    destroy_number(new_number);
    return res;
}

int get_size_of_int(int number)
{
    int size = 0;

    if (number == 0)
        return 1;
    for (int tmp = number; tmp != 0; tmp /= 10)
        size++;
    return size;
}
