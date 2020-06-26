%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    push ebp
    mov ebp, esp


    mov eax, 211    ; to be broken down into powers of 2
    mov ebx, 1      ; stores the current power
    

    ; TODO - print the powers of 2 that generate number stored in EAX    
    mov ecx, 0
    jmp check_index
  
    leave
    ret    

check_index:
    cmp ecx, 10
    je end
    add ecx, 1
 
    mov edx, eax
    and edx, ebx
    test edx, edx
    jne print_ebx
    jmp shift 

print_ebx:
    PRINT_UDEC 4, ebx
    NEWLINE
    jmp shift

shift: 
    shl ebx, 1
    jmp check_index
    
end:
    leave
    ret  