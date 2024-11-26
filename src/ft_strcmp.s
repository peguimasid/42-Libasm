section .text
  global ft_strcmp

ft_strcmp:
  mov rcx, 0
  mov r8, 0
  mov r9, 0

loop:
  movzx r8, byte [rdi + rcx]
  movzx r9, byte [rsi + rcx]
  cmp r8, 0
  je break
  cmp r9, 0
  je break
  cmp r8, r9
  jne break
  inc rcx
  jmp loop

break:
  sub r8, r9 
  mov rax, r8
  ret

section .note.GNU-stack
