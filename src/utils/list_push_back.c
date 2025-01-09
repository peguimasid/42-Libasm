#include "../libasm.h"

void list_push_back(t_list **list, t_list *new_node) {
  t_list *tail;

  if (!new_node) return;

  if (!*list) {
    *list = new_node;
    return;
  }

  tail = list_last(*list);
  tail->next = new_node;
}
