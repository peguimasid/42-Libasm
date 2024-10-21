global _start

section .text
_start:
  mov ebx, 42 ; exit status 42
  mov eax, 1 ; sys_exit system call
  jmp skip ; jump to "skip" label
  mov ebx, 12 ; exit status is 12

skip:
  int 0x80
