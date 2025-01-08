#include "../libasm.h"

int list_size(t_list *list) {
  int result = 0;

  while (list) {
    list = list->next;
    result++;
  }

  return result;
}
