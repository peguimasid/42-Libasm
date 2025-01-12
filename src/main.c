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

void run_write_test(int fd, char *str, int len) {
  errno = 0;
  int actual_result = ft_write(fd, str, len);
  int actual_errno = errno;

  errno = 0;
  int expected_result = write(fd, str, len);
  int expected_errno = errno;

  if (actual_result == expected_result && actual_errno == expected_errno) {
    printf(GREEN);
    printf("✓ ft_write(%d, \"%s\", %d) = %d, errno = %d\n", fd, str, len, actual_result, actual_errno);
  } else {
    printf(RED);
    printf("✕ ft_write(%d, \"%s\", %d) = %d, expected %d, errno = %d, expected errno = %d\n", fd, str, len, actual_result, expected_result, actual_errno, expected_errno);
  }
  printf(RESET);
}

void execute_write_tests() {
  printf(BOLD "\n➜ Testing: ft_write \n" RESET);

  int file_fd = open("write_tests.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

  int fds[] = {file_fd, 100, -1};

  for (int i = 0; i < 3; i++) {
    int fd = fds[i];

    run_write_test(fd, "", 0);
    run_write_test(fd, "A", 1);
    run_write_test(fd, "This is a longer string to test the function.", 45);
    run_write_test(fd, "1234567890", 10);
    run_write_test(fd, "Special characters !@#$%^&*()", 30);
    run_write_test(fd, "test12345", 9);
    run_write_test(fd, "1", 1);
    run_write_test(fd, "test", 4);
    run_write_test(fd, "zzzzzzzzzzzzzzzzzzzzzzzz hey", 29);
  }

  close(file_fd);
}

void run_read_test(int fd, int len) {
  char actual_buf[BUFFER_SIZE];
  char expected_buf[BUFFER_SIZE];

  errno = 0;
  int actual_result = ft_read(fd, actual_buf, len);
  int actual_errno = errno;

  lseek(fd, 0, SEEK_SET);

  errno = 0;
  int expected_result = read(fd, expected_buf, len);
  int expected_errno = errno;

  lseek(fd, 0, SEEK_SET);

  actual_buf[actual_result == -1 ? 0 : actual_result] = '\0';
  expected_buf[expected_result == -1 ? 0 : expected_result] = '\0';

  if (actual_result == expected_result && actual_errno == expected_errno && strcmp(actual_buf, expected_buf) == 0) {
    printf(GREEN);
    printf("✓ ft_read(%d, %d) = \"%s\", %d, errno = %d\n", fd, len, actual_buf, actual_result, actual_errno);
  } else {
    printf(RED);
    printf("✕ ft_read(%d, %d) = \"%s\", %d, expected \"%s\", %d, errno = %d, expected errno = %d\n", fd, len, actual_buf, actual_result, expected_buf, expected_result, actual_errno, expected_errno);
  }
  printf(RESET);
}

void execute_read_tests() {
  printf(BOLD "\n➜ Testing: ft_read \n" RESET);

  int file_fd = open("./utils/lorem.txt", O_RDONLY);

  int fds[] = {file_fd, 100, -1};

  for (int i = 0; i < 3; i++) {
    int fd = fds[i];

    run_read_test(fd, 0);
    run_read_test(fd, 1);
    run_read_test(fd, 45);
    run_read_test(fd, 10);
    run_read_test(fd, 30);
  }

  close(file_fd);
}

void run_strdup_test(char *str1) {
  char *actual = ft_strdup(str1);
  char *expected = strdup(str1);

  bool isSameAddress = str1 == actual;
  bool areStringsEqual = strcmp(actual, expected) == 0;

  if (!isSameAddress && areStringsEqual) {
    printf(GREEN);
    printf("✓ ft_strdup(\"%s\") = \"%s\"\n", str1, actual);
  } else {
    printf(RED);
    printf("✕ ft_strdup(\"%s\") = \"%s\", expected \"%s\"\n", str1, actual, expected);
  }
  printf(RESET);
}

void execute_strdup_tests() {
  printf(BOLD "\n➜ Testing: ft_strdup \n" RESET);

  run_strdup_test("this is a test");
  run_strdup_test("1");
  run_strdup_test("test");
  run_strdup_test("");
  run_strdup_test("\0");
  run_strdup_test("424242");
}

void run_atoi_base_test(char *str, int base) {
  int actual = ft_atoi_base(str, base);
  int expected = atoi_base(str, base);

  if (actual == expected) {
    printf(GREEN);
    printf("✓ ft_atoi_base(\"%s\", %d) = %d\n", str, base, actual);
  } else {
    printf(RED);
    printf("✕ ft_atoi_base(\"%s\", %d) = %d, expected %d\n", str, base, actual, expected);
  }
  printf(RESET);
}

void execute_atoi_base_tests() {
  printf(BOLD "\n➜ Testing: ft_atoi_base \n" RESET);

  run_atoi_base_test("10", 2);
  run_atoi_base_test("1A", 16);
  run_atoi_base_test("123", 10);
  run_atoi_base_test("-1A", 16);
  run_atoi_base_test("   42", 10);
  run_atoi_base_test("   -42", 10);
  run_atoi_base_test("7F", 16);
  run_atoi_base_test("101", 2);
  run_atoi_base_test("0", 10);
  run_atoi_base_test("Z", 36);  // Invalid base, should return 0
}

void run_list_size_test(t_list *list) {
  int actual = ft_list_size(list);
  int expected = list_size(list);

  if (actual == expected) {
    printf(GREEN);
    printf("✓ ft_list_size() = %d\n", actual);
  } else {
    printf(RED);
    printf("✕ ft_list_size() = %d, expected %d\n", actual, expected);
  }
  printf(RESET);
}

void execute_list_size_tests() {
  printf(BOLD "\n➜ Testing: ft_list_size \n" RESET);

  t_list *list = NULL;
  run_list_size_test(list);

  for (int i = 0; i < 10; i++) {
    list_push_back(&list, itoa(i));
    run_list_size_test(list);
  }
}

int main() {
  printf(BOLD "\n############ MANDATORY ############ \n" RESET);
  execute_strlen_tests();
  execute_strcpy_tests();
  execute_strcmp_tests();
  execute_write_tests();
  execute_read_tests();
  execute_strdup_tests();
  printf(BOLD "\n############ BONUS ############ \n" RESET);
  // execute_atoi_base_tests();
  execute_list_size_tests();

  t_list *list = NULL;
  list_push_back(&list, "first");
  char *result = ft_list_push_front(&list, "second");
  printf(">> %s\n", result);

  return 0;
}
