extern __errno_location

section .text
  global ft_write

ft_write:
  mov rax, 1
  ; This is unnecessary because the registers already hold the values
  ; mov rdi, rdi ; file descriptor
  ; mov rsi, rsi ; buffer
  ; mov rdx, rdx ; count
  syscall
  ; jc error
  ret

; error:
;   mov r8, rax
;   call __errno_location
;   mov [rax], r8
;   mov rax, -1
;   ret

section .note.GNU-stack
