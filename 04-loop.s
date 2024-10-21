global _start

section .text
_start:
	mov ebx, 1 ; start ebx at 1
  mov ecx, 4 ; number of iterations
  jmp masid;

masid:
  add ebx, ebx ; ebx += ebx
	dec ecx ; exc -= 1
  mov eax, 1 ; ecx -= 1
  cmp ecx, 0 ; compare ecx with 0
  jg masid ; jump to masid if greater
  mov eax, 1 ; sys_exit system call
  int 0x80
