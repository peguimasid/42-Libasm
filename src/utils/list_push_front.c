#include "../libasm.h"

void list_push_front(t_list **list, t_list *new_node) {
  if (!list || !new_node) return;

  new_node->next = *list;
  *list = new_node;
}
