global ft_strcmp

section .text

ft_strcmp:
  xor rcx, rcx ; Initialize index counter to 0
  xor r8, r8   ; Initialize r8 to 0 (will hold characters from s1)
  xor r9, r9   ; Initialize r9 to 0 (will hold characters from s2)

; We need to use movzx because we're moving an 8-bit value
; ([rdi + rcx]) into a 64-bit register (r8)

loop:
  movzx r8, byte [rdi + rcx] ; Load byte from s1[rcx] into r8 with zero extension
  movzx r9, byte [rsi + rcx] ; Load byte from s2[rcx] into r9 with zero extension
  cmp r8, 0                  ; Compare r8 with null terminator
  cmp r9, 0                  ; Compare r9 with null terminator
  jz break                   ; If zero flag is set, break
  cmp r8, r9                 ; Compare characters from s1 and s2
  jne break                  ; If characters are different, break
  inc rcx                    ; Increment index counter
  jmp loop                   ; Repeat loop

break:
  sub r8, r9                 ; Calculate difference between characters
  mov rax, r8                ; Move result to rax (return value)
  ret                        ; Return

section .note.GNU-stack
