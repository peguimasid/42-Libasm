global main
extern printf

section .data
	msg db "Testing %i...", 0x0a, 0x00

section .text
main:
  ;prolog
	push rbp
	mov rbp,rsp
  
	lea rdi,[rel msg]		;load 1st param to printf need to use lea due to PIE
	mov rsi,123
	call printf wrt ..plt
	mov rax,0

  ;epilog
	mov rsp,rbp
	pop rbp
	ret

section .note.GNU-stack
