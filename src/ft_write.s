section .text
  global ft_write

ft_write:
  mov rax, 1
  ; This is unnecessary because the registers already hold the values
  ; mov rdi, rdi ; file descriptor
  ; mov rsi, rsi ; buffer
  ; mov rdx, rdx ; count
  syscall
  ret

section .note.GNU-stack
