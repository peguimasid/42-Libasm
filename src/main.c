#include "libasm.h"

void run_strlen_test(char *str) {
  int result = ft_strlen(str);
  int expected = strlen(str);

  if (result == expected) {
    printf(GREEN);
    printf("✓ ft_strlen(\"%s\") = %d\n", str, result);
  } else {
    printf(RED);
    printf("✕ ft_strlen(\"%s\") = %d, expected %d\n", str, result, expected);
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

int main() {
  execute_strlen_tests();
  return 0;
}
