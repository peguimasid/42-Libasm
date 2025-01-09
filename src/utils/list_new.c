#include "../libasm.h"

t_list *list_new(void *data) {
  t_list *new_node = (t_list *)malloc(sizeof(t_list));

  if (!new_node) {
    return NULL;
  }

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}
