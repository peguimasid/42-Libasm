global ft_list_push_front

section .data
  str42 db '42', 0  ; Define the string "42" with a null terminator

section .text

ft_list_push_front:
  mov rax, str42

break:
  ret

section .note.GNU-stack
