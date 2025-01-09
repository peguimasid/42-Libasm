#include "../libasm.h"

void list_push_back(t_list **list, void *data) {
  t_list *new_node = list_new(data);

  if (!new_node) return;

  if (!*list) {
    *list = new_node;
    return;
  }

  t_list *tail = list_last(*list);
  tail->next = new_node;
}
