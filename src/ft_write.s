extern __errno_location

section .text
  global ft_write

ft_write:
  mov rax, 1 ; set system call to write
  ; This is unnecessary because the registers already hold the values
  ; mov rdi, rdi ; file descriptor
  ; mov rsi, rsi ; buffer
  ; mov rdx, rdx ; count
  syscall    ; result = write(fd, buffer, count)
  cmp rax, 0 ; if result < 0
  jl error
  ret

error:
  mov r8, rax                     ; tmp = result
  call __errno_location wrt ..plt ; result = &errno
  neg r8                          ; tmp = -tmp -> only the abs value
  mov [rax], r8                   ; *result = tmp
  mov rax, -1                     ; result = -1
  ret

section .note.GNU-stack
