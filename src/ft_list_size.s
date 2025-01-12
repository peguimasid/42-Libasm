global ft_list_size

section .text

ft_list_size:
  xor rax, rax ; rax = 0
  cmp rdi, 0   ; if list == NULL
  je break     ; return

loop:
  inc rax             ; result++
  mov rdi, [rdi + 8]  ; list = list->next
  cmp rdi, 0          ; if list != NULL
  jne loop            ; jump to loop

break:
  ret

section .note.GNU-stack
