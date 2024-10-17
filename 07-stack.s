global _start

section .text
_start:
	sub rsp, 4
  mov [rsp], byte 'H'
  mov [rsp + 1], byte 'e'
  mov [rsp + 2], byte 'y'
  mov [rsp + 3], byte 10
	mov rax, 1 ; sys_write system call
	mov rdx, 1 ; stdout file descriptor
	mov rsi, rsp ; bytes to write
	mov rdx, 4 ; number of bytes to write
	syscall ; perform system call
	mov rax, 60 ; sys_exit system call
	mov rdi, 0 ; exit status is 0
	syscall

