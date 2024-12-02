section .text
  global ft_strcpy

ft_strcpy:
  xor rcx, rcx

loop:
  mov al, [rsi + rcx] ; al = src[rcx]
  mov [rdi + rcx], al ; dst[rcx] = al
  inc rcx             ; rcx++
  cmp al, 0           ; is al the end of string?
  je break            ; jump to break if is equal (je -> jump if equal)
  jmp loop            ; jump to loop if not is equal <- This only executes if line 12 don't execute, so it works like an else

break:
  mov rax, rdi
  ret

section .note.GNU-stack
