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

void run_strcmp_test(char *str1, char *str2) {
  int actual = ft_strcmp(str1, str2);
  int expected = strcmp(str1, str2);

  if (actual == expected) {
    printf(GREEN);
    printf("✓ ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str2, actual);
  } else {
    printf(RED);
    printf("✕ ft_strcmp(\"%s\", \"%s\") = %d, expected %d\n", str1, str2, actual, expected);
  }
  printf(RESET);
}

void execute_strcmp_tests() {
  printf(BOLD "\n➜ Testing: ft_strcmp \n" RESET);

  run_strcmp_test("test123456709123", "test1234567");
  run_strcmp_test("1", "2");
  run_strcmp_test("test", "test2");
  run_strcmp_test("test", "Test");
  run_strcmp_test("test", "tesT");
  run_strcmp_test("test", "test");
  run_strcmp_test("", "");
  run_strcmp_test("4242424242", "4242244242");
}

int main() {
  // execute_strlen_tests();
  // execute_strcpy_tests();
  // execute_strcmp_tests();
  ft_write(1, "Hello\n", 6);
  return 0;
}
