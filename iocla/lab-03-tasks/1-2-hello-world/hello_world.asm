%include "io.inc"

section .data
    myString: db "Hello, World!",0
    GBString: db "Goodbye, world!",0

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ecx, 6                 ; N = valoarea registrului ecx
    mov eax, 2
    mov ebx, 1
    ;cmp ebx, ecx
    jmp check_index                  ; TODO1: eax > ebx?
    ;jmp print_goodbye
    ;ret
    
check_index:    
    cmp ebx, ecx
    je print_goodbye
    add ebx, 1
    jmp print_hello
     
print_hello:
    PRINT_STRING myString
    NEWLINE
                               ; TODO2.2: afisati "Hello, World!" de N ori
                               ; TODO2.1: afisati "Goodbye, World!"
    jmp check_index

print_goodbye:
    PRINT_STRING GBString
    NEWLINE
    
    ret
