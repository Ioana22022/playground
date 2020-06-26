%include "io.inc"

section .text
global CMAIN
CMAIN:
    ;cele doua numere se gasesc in eax si ebx
    mov eax, 4
    mov ebx, 1 
    ; TODO: aflati minimul
    cmp eax, ebx
    jg ebx_min
    jmp print_eax
    

    
ebx_min:
    xchg eax, ebx
    jmp print_eax
    
print_eax:
    PRINT_DEC 4, eax ; afiseaza minimul
    NEWLINE

    ret