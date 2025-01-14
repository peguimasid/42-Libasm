global ft_list_push_front

extern ft_list_new

section .text

ft_list_push_front:  ; rdi(head) rsi(data)
  test rdi, rdi         ; if head == NULL
  jz break              ; break

  push rdi              ; stack.push(head)
  mov rdi, rsi          ; rdi = data
  call ft_list_new      ; new_node = ft_list_new(rdi)
  test rax, rax         ; if new_node == NULL
  jz break              ; break

  pop rdi               ; head = stack.pop()
  mov r8, [rdi]         ; tmp = *head
  mov [rax + 8], r8     ; new_node->next = tmp
  mov [rdi], rax        ; head = new_node

break:
  ret

section .note.GNU-stack
