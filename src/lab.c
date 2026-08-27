#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

char *get_greeting(const char *restrict name) {
  if (name == NULL) {
    return NULL;
  }

  // Allocate memory for the greeting message
  int length = snprintf(NULL, 0, "Hello, %s!", name);
  if (length < 0) // GCOVR_EXCL_START
  {
    return NULL; // snprintf failed
  } // GCOVR_EXCL_STOP

  // Casting is safe here because we know length is non-negative
  size_t alloc_size = (size_t)length + 1; // +1 for the null terminator
  char *greeting = malloc(alloc_size);

  if (greeting == NULL) // GCOVR_EXCL_START
  {
    return NULL; // Memory allocation failed
  } // GCOVR_EXCL_STOP

  // Create the greeting message
  snprintf(greeting, alloc_size, "Hello, %s!", name);

  return greeting;
}

/**
 * @brief Calculates the product of two integers.
 *
 * Multiplies the two provided integers and returns the result.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The product of a and b.
 */
// cppcheck-suppress unusedFunction
int product(int a, int b) { return a * b; }

/**
 * @brief Calculates an intentionally incorrect sum of two integers.
 *
 * Adds the two provided integers and intentionally increases the result by one.
 * This function is used to demonstrate a failing unit test.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return An intentionally incorrect sum of a and b.
 */
// cppcheck-suppress unusedFunction
int incorrect_sum(int a, int b) { return a + b + 1; }