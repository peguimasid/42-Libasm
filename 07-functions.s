global _start

_start:
  call func
	mov rax, 60 ; sys_exit system call
  syscall

func:
  mov rdi, 42 ; set status to be 42
  ret
