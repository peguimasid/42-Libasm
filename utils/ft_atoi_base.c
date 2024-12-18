#include <stdio.h>
#include <stdlib.h>

int is_blank(char c) {
  return c <= 32;
}

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

int ft_atoi_base(const char *str, int str_base) {
  int result = 0;
  int sign = 1;

  int i = 0;

  if (str_base > 16) return 0;

  while (is_blank(str[i])) {
    i++;
  }

  if (str[i] == '-') {
    sign = -1;
  }

  if (str[i] == '+' || str[i] == '-') {
    i++;
  }

  while (is_valid(str[i], str_base)) {
    result *= str_base;
    result += value_of(str[i++]);
  }

  return (result * sign);
}

int main() {
  // Test base 10
  printf(">>>>>>>>> Test base 10\n");
  if (ft_atoi_base("123", 10) == 123)
    printf("123: pass\n");
  else
    printf("expected: 123 got: %d\n", ft_atoi_base("123", 10));
  if (ft_atoi_base("-123", 10) == -123)
    printf("-123: pass\n");
  else
    printf("expected: -123 got: %d\n", ft_atoi_base("-123", 10));
  if (ft_atoi_base("+123", 10) == 123)
    printf("+123: pass\n");
  else
    printf("expected: 123 got: %d\n", ft_atoi_base("+123", 10));
  if (ft_atoi_base("0", 10) == 0)
    printf("0: pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("0", 10));
  if (ft_atoi_base("   42", 10) == 42)
    printf("42: pass\n");
  else
    printf("expected: 42 got: %d\n", ft_atoi_base("   42", 10));

  // Test base 16
  printf(">>>>>>>>> Test base 16\n");
  if (ft_atoi_base("7B", 16) == 123)
    printf("7B: pass\n");
  else
    printf("expected: 123 got: %d\n", ft_atoi_base("7B", 16));
  if (ft_atoi_base("7b", 16) == 123)
    printf("7b: pass\n");
  else
    printf("expected: 123 got: %d\n", ft_atoi_base("7b", 16));
  if (ft_atoi_base("-7B", 16) == -123)
    printf("-7B: pass\n");
  else
    printf("expected: -123 got: %d\n", ft_atoi_base("-7B", 16));
  if (ft_atoi_base("0", 16) == 0)
    printf("0: pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("0", 16));
  if (ft_atoi_base("   2A", 16) == 42)
    printf("2A: pass\n");
  else
    printf("expected: 42 got: %d\n", ft_atoi_base("   2A", 16));

  // Test base 8
  printf(">>>>>>>>> Test base 8\n");
  if (ft_atoi_base("173", 8) == 123)
    printf("173: pass\n");
  else
    printf("expected: 123 got: %d\n", ft_atoi_base("173", 8));
  if (ft_atoi_base("-173", 8) == -123)
    printf("-173: pass\n");
  else
    printf("expected: -123 got: %d\n", ft_atoi_base("-173", 8));
  if (ft_atoi_base("0", 8) == 0)
    printf("0: pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("0", 8));
  if (ft_atoi_base("   52", 8) == 42)
    printf("52: pass\n");
  else
    printf("expected: 42 got: %d\n", ft_atoi_base("   52", 8));

  // Test base 2
  printf(">>>>>>>>> Test base 2\n");
  if (ft_atoi_base("1111011", 2) == 123)
    printf("1111011: pass\n");
  else
    printf("expected: 123 got: %d\n", ft_atoi_base("1111011", 2));
  if (ft_atoi_base("-1111011", 2) == -123)
    printf("-1111011: pass\n");
  else
    printf("expected: -123 got: %d\n", ft_atoi_base("-1111011", 2));
  if (ft_atoi_base("0", 2) == 0)
    printf("0: pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("0", 2));
  if (ft_atoi_base("   101010", 2) == 42)
    printf("101010: pass\n");
  else
    printf("expected: 42 got: %d\n", ft_atoi_base("   101010", 2));

  // Test invalid inputs
  printf(">>>>>>>>> Test invalid inputs\n");
  if (ft_atoi_base("123", 1) == 0)
    printf("123 (base 1): pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("123", 1));
  if (ft_atoi_base("123", 37) == 0)
    printf("123 (base 37): pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("123", 37));
  if (ft_atoi_base("G", 16) == 0)
    printf("G (base 16): pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("G", 16));
  if (ft_atoi_base("9", 8) == 0)
    printf("9 (base 8): pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("9", 8));
  if (ft_atoi_base("2", 2) == 0)
    printf("2 (base 2): pass\n");
  else
    printf("expected: 0 got: %d\n", ft_atoi_base("2", 2));

  printf("All tests completed!\n");
}
