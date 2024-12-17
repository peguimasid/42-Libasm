global ft_strcpy

section .text

ft_strcpy:
  xor rcx, rcx

loop:
  mov al, [rsi + rcx] ; al = src[rcx]
  mov [rdi + rcx], al ; dst[rcx] = al
  inc rcx             ; rcx++
  cmp al, 0           ; is al the end of string?
  jne loop            ; jump to loop if not is equal

break:
  mov rax, rdi
  ret

section .note.GNU-stack
