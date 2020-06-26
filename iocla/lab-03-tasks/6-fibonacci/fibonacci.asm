%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov eax, 7       ; vrem sa aflam al N-lea numar; N = 7
    ; TODO: calculati al N-lea numar fibonacci (f(0) = 0, f(1) = 1)
    mov ebx, 0
    mov ecx, 1
    mov edx, 1
    
    jmp check_index
    ret
    
    
check_index:
    cmp eax, 0
    je print_fib
    sub eax, 1
    
    ; edx = ecx + ebx
    ; ebx = ecx
    ; ecx = edx
    
    mov edx, ecx
    add edx, ebx
    
    mov ebx, ecx
    mov ecx, edx
    
    jmp check_index
    
print_fib:
    PRINT_DEC 4, edx