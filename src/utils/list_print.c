#include "../libasm.h"

void list_print(t_list *list) {
  while (list) {
    printf("%d", *(int *)list->data);
    if (list->next) printf(" -> ");
    list = list->next;
  }
  printf("\n");
}
