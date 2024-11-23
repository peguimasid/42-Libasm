section .text
  global ft_strcpy

ft_strcpy:
  mov rcx, 0

loop:
  mov al, [rsi + rcx] ; al = src[rcx]
  mov [rdi + rcx], al ; dst[rcx] = al
  inc rcx             ; rcx++
  cmp al, 0           ; is al the end of string?
  jne loop            ; jump to loop if not is (jne -> jump if not equal)

break:
  mov rax, rdi
  ret

section .note.GNU-stack
