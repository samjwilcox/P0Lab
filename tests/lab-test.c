#include "../src/lab.h"
#include "harness/unity.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void) { printf("Setting up tests...\n"); }

void tearDown(void) { printf("Tearing down tests...\n"); }

void test_get_greeting(void) {
  char *greeting = get_greeting("Alice");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", greeting);
  free(greeting); // Free the allocated memory for the greeting

  greeting = get_greeting(NULL);
  TEST_ASSERT_NULL(greeting);

  greeting = get_greeting("");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, !", greeting);
  free(greeting);
}

void test_product(void) { TEST_ASSERT_EQUAL_INT(6, product(2, 3)); }

void test_incorrect_sum(void) { TEST_ASSERT_EQUAL_INT(6, incorrect_sum(2, 3)); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_get_greeting);
  RUN_TEST(test_product);
  RUN_TEST(test_incorrect_sum);

  return UNITY_END();
}
