#ifndef LAB_H
#define LAB_H

/** * @brief Returns a greeting message.
 *
 * This function returns a string that contains a greeting message.
 * The string is allocated with malloc and should be freed by the caller.
 * @param name The name to include in the greeting.
 * @return A greeting string.
 */
char *get_greeting(const char *restrict name);

/**
 * @brief Returns the product of two numbers.
 */
int product(int a, int b);

/**
 * @brief Returns an intentionally incorrect sum of two numbers.
 */
int incorrect_sum(int a, int b);

#endif // LAB_H
