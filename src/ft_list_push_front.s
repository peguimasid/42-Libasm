global ft_list_push_front

section .text

ft_list_push_front:
  mov rax, [rdi]        ; Move the list pointer to rax
  mov rax, [rax]        ; Dereference the list pointer to get the data field

break:
  ret

section .note.GNU-stack
