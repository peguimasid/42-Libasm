section .text
  global ft_strlen

ft_strlen:
  xor rcx, rcx

loop:
  cmp byte [rdi + rcx], 0 ; is str[rcx] the end of the string?
  je break                ; if is jump to break (je -> jump if equal)
  inc rcx                 ; rcx++
  jmp loop                ; repeat loop

break:
  mov rax, rcx ; set the return value to be rcx
  ret

section .note.GNU-stack
