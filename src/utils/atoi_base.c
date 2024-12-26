#include <stdio.h>
#include <stdlib.h>

// Checks if a character is a blank space
int is_blank(char c) {
  return c <= 32;
}

// Checks if a character is valid in the given base
int is_valid(char c, int base) {
  char digits[17] = "0123456789abcdef";
  char digits2[17] = "0123456789ABCDEF";

  while (base--) {
    if (digits[base] == c || digits2[base] == c) {
      return (1);
    }
  }

  return (0);
}

// Returns the integer value of a character
int value_of(char c) {
  if (c >= '0' && c <= '9') {
    return (c - '0');
  }
  if (c >= 'a' && c <= 'f') {
    return (c - 'a' + 10);
  }
  if (c >= 'A' && c <= 'F') {
    return (c - 'A' + 10);
  }
  return (0);
}

// Converts a string in a given base to an integer
int atoi_base(const char *str, int str_base) {
  int result = 0;
  int sign = 1;
  int i = 0;

  if (str_base > 16) return 0;

  // Skip leading blank spaces
  while (is_blank(str[i])) {
    i++;
  }

  // Check for sign
  if (str[i] == '-') {
    sign = -1;
  }
  if (str[i] == '+' || str[i] == '-') {
    i++;
  }

  // Convert valid characters to integer
  while (is_valid(str[i], str_base)) {
    result *= str_base;
    result += value_of(str[i++]);
  }

  return (result * sign);
}
