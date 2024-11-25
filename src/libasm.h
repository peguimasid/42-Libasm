#pragma once

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1m"

#define BUFFER_SIZE 100

#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(char *s1, char *s2);
