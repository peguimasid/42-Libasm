global ft_list_size

section .text

ft_list_size:
  xor rax, rax
  cmp rdi, 0
  je break

loop:
  inc rax
  mov rdi, [rdi + 8]
  cmp rdi, 0
  jne loop

break:
  ret

section .note.GNU-stack
