/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Include file for infinite number
*/

#ifndef ZAPPY_NUMBER_H
    #define ZAPPY_NUMBER_H

    #ifdef __cplusplus
extern "C" {
    #endif // __cplusplus

    enum operation_e {
        ADD = 0,
        SUBTRACT = 1
    };

    /**
     * @struct number_s
     *
     * This structure represents an infinite number.
     * Stock on a char * where each char is a digit.
     */
    typedef struct number_s {
        char *number;
    } number_t;

    /**
     * @brief Create a new infinite number with an integer.
     *
     * @param number The number to create.
     * @return The new infinite number.
     */
    number_t *create_number_with_int(int number);

    /**
     * @brief Create a new infinite number with a string.
     *
     * @param number The number to create.
     * @return The new infinite number.
     */
    number_t *create_number_with_string(char *number);

    /**
     * @brief Destroy an infinite number.
     *
     * @param number The number to destroy.
     */
    void destroy_number(number_t *number);

    /**
     * @brief Add two infinite numbers.
     *
     * @param number1 The first number.
     * @param number2 The second number.
     * @return The sum of the two numbers.
     */
    void add_numbers(number_t *number1, number_t *number2);

    /**
     * @brief Subtract two infinite numbers.
     *
     * @param number1 The first number.
     * @param number2 The second number.
     * @return The difference of the two numbers.
     */
    void subtract_numbers(number_t *number1, number_t *number2);

    /**
     * @brief Add int to infinite number.
     *
     * @param number The infinite number.
     * @param nb The int to add.
     * @return The sum of the infinite number and the int.
     */
    void add_int_to_number(number_t *number, int nb);

    /**
     * @brief Subtract int to infinite number.
     *
     * @param number The infinite number.
     * @param nb The int to subtract.
     * @return The difference of the infinite number and the int.
     */
    void subtract_int_to_number(number_t *number, int nb);

    /**
     * @brief Compare int to infinite number.
     *
     * @param number The infinite number.
     * @param nb The int to compare.
     * @return 0 if the numbers are equal, 1 if the first number is greater,
     * -1 if the second number is greater.
     */
    int compare_int_to_number(number_t *number, int nb);

    /**
     * @brief Get size of an integer
     *
     * @param number The number to get the size.
     * @return The size of the number.
     */
    int get_size_of_int(int number);

    #ifdef __cplusplus
}
    #endif // __cplusplus

#endif //ZAPPY_NUMBER_H

