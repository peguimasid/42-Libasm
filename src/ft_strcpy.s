section .text
  global ft_strcpy

ft_strcpy:
  mov rcx, 0 ; Initialize counter to 0

loop:
  cmp byte [rsi + rcx], 0 ; Compare the current character with null terminator
  je break ; If null terminator, jump to break
  inc rcx ; Increment counter
  jmp loop ; Repeat the loop

break:
  mov rax, rcx ; Move the counter to rax (return value)
  ret

section .note.GNU-stack
