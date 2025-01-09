#include "../libasm.h"

void list_push_front(t_list **list, void *data) {
  t_list *new_node = list_new(data);

  if (!list || !new_node) return;

  new_node->next = *list;
  *list = new_node;
}
