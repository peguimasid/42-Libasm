section .text
  global ft_strcmp

ft_strcmp:
  mov rcx, 0

loop:
  cmp byte [rdi + rcx], 0
  je break
  inc rcx
  jmp loop

break:
  mov rax, rcx ; set the return value to be rcx
  ret

section .note.GNU-stack
