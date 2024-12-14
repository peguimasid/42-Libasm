global ft_read

extern __errno_location

section .text

ft_read:
  mov rax, 0 ; set system call to write
  ; This is unnecessary because the registers already hold the values
  ; mov rdi, rdi ; file descriptor
  ; mov rsi, rsi ; buf
  ; mov rdx, rdx ; nbyte
  syscall    ; result = read(fd, buf, nbyte)
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
