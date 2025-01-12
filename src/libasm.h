#pragma once

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1m"

#define BUFFER_SIZE 100

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

// Mandatory
int ft_strlen(char *str);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(char *s1, char *s2);
ssize_t ft_write(unsigned int fd, const char *str, size_t len);
ssize_t ft_read(int fd, void *buf, size_t nbyte);
char *ft_strdup(const char *s1);

// Bonus
int ft_atoi_base(const char *str, int str_base);
int ft_list_size(t_list *head);
// TODO: replace with void return
int ft_list_push_front(t_list **head, void *data);

// Utils
int atoi_base(const char *str, int str_base);
int list_size(t_list *list);
void list_push_front(t_list **list, void *data);
void list_push_back(t_list **list, void *data);
void list_print(t_list *list);
t_list *list_last(t_list *list);
t_list *list_new(void *data);
char *itoa(int n);
