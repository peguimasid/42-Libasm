#include "libasm.h"

void run_strlen_test(char *str) {
  int actual = ft_strlen(str);
  int expected = strlen(str);

  if (actual == expected) {
    printf(GREEN);
    printf("✓ ft_strlen(\"%s\") = %d\n", str, actual);
  } else {
    printf(RED);
    printf("✕ ft_strlen(\"%s\") = %d, expected %d\n", str, actual, expected);
  }
  printf(RESET);
}

void execute_strlen_tests() {
  printf(BOLD "\n➜ Testing: ft_strlen \n" RESET);

  run_strlen_test("Hello World!");
  run_strlen_test("");
  run_strlen_test("A");
  run_strlen_test("This is a longer string to test the function.");
  run_strlen_test("1234567890");
  run_strlen_test("Special characters !@#$%^&*()");
  run_strlen_test("test12345");
  run_strlen_test("1");
  run_strlen_test("test");
  run_strlen_test("zzzzzzzzzzzzzzzzzzzzzzzz hey");
}

void run_strcpy_test(char *str) {
  char actual[BUFFER_SIZE];
  char expected[BUFFER_SIZE];

  ft_strcpy(actual, str);
  strcpy(expected, str);

  if (strcmp(actual, expected) == 0) {
    printf(GREEN);
    printf("✓ ft_strcpy(\"%s\") = \"%s\"\n", str, actual);
  } else {
    printf(RED);
    printf("✕ ft_strcpy(\"%s\") = \"%s\", expected \"%s\"\n", str, actual, expected);
  }
  printf(RESET);
}

void execute_strcpy_tests() {
  printf(BOLD "\n➜ Testing: ft_strcpy \n" RESET);

  run_strcpy_test("Hello World!");
  run_strcpy_test("");
  run_strcpy_test("A");
  run_strcpy_test("This is a longer string to test the function.");
  run_strcpy_test("1234567890");
  run_strcpy_test("Special characters !@#$%^&*()");
  run_strcpy_test("test12345");
  run_strcpy_test("1");
  run_strcpy_test("test");
  run_strcpy_test("zzzzzzzzzzzzzzzzzzzzzzzz hey");
}

int main() {
  execute_strlen_tests();
  execute_strcpy_tests();
  return 0;
}
