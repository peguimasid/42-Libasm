global _start

_start:
  push 21
  call times2
  mov rdi, rax
  mov rax, 60
  syscall

times2:
  push rbp
  mov rbp, rsp
  mov rax, [rbp + 16]
  add rax, rax
  mov rsp, rbp
  pop rbp
  ret
