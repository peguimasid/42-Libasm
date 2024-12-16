global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

section .text

ft_strdup:
  call ft_strlen        ; int result = strlen(string)
  inc rax               ; result++
  push rdi              ; tmp = string
  mov rdi, rax          ; size = result
  call malloc wrt ..plt ; result = malloc(size)
  pop rsi               ; src = tmp
  mov rdi, rax          ; dst = result
  call ft_strcpy        ; result = ft_strcpy(dst, src)
  ret

section .note.GNU-stack
