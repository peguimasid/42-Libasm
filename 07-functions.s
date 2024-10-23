global _start

_start:
  call func ; this will push the next line into `rax` register
	mov rax, 60 ; sys_exit system call
  syscall

func:
  mov rdi, 42 ; set status to be 42
  pop rax ; now we pop the `rax`
  jmp rax ; and jump to it
