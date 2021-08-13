extern printf

section .data
    fmtStr: db 'printf: a1 - %i, a2 - %s',0xA,0
    param1: db 'Parameter String'
  
section .text
 global main
main:
    sub     esp, 4          ; Allocate space on the stack for one 4 byte parameter
    lea     eax, [param1]   ; Load string into eax
    mov     [esp], eax      ; Copy eax into the address of esp
    sub     esp, 4          ; Allocate space on the stack for one 4 byte parameter
    mov     eax, 8          ; Copy 8 into eax
    add     eax, 1098       ; eax = eax + 1098
    mov     [esp], eax      ; Copy eax into the address of esp
    sub     esp, 4          ; Allocate space on the stack for one 4 byte parameter
    lea     eax, [fmtStr]   ; Load string into eax
    mov     [esp], eax      ; Copy eax into the address of esp
    call    printf          ; Call printf(3):
    add     esp, 12         ; Pop the stack (There were 3 "sub esp,4")
    ret
