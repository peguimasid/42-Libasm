global main
extern printf

section .data
  msg db "Testing %i...", 0x0a, 0x00

section .text
main:
  push rbp
  mov rbp, rsp
  push 123
  push msg
  call printf
  mov rax, 0
  mov rsp, rbp
  pop rbp
  ret
