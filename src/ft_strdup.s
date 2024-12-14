global ft_strdup

extern _malloc
extern ft_strlen
extern ft_strcpy

section .data
  hello_string db 'hello', 0

section .text

ft_strdup:
  mov rax, hello_string
  ret

section .note.GNU-stack
