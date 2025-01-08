global ft_list_size

section .text

ft_list_size:
  cmp rdi, 0          ; Compare the current node pointer to NULL
  je break            ; If it is NULL, we are done
  mov rax, [rdi]      ; Move the data of the current node into rax
  
break:
  ret                 ; Return the data in rax

section .note.GNU-stack
