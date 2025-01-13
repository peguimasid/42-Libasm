global ft_list_new

extern malloc

section .text

ft_list_new:
  push rdi                ; stack.push(data)
  mov rdi, 16             ; rdi = 16
  call malloc wrt ..plt   ; result = malloc(rdi)
  test rax, rax           ; if result == NULL
  jz break                ; return NULL
  pop rdi                 ; rdi = stack.pop()
  mov [rax], rdi          ; [rax] = rdi
  mov qword [rax + 8], 0  ; [rax + 8] = NULL (assuming 64-bit pointers)

break:
  ret

section .note.GNU-stack
