%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;cele doua multimi se gasesc in eax si ebx
    mov eax, 139 
    mov ebx, 169
    PRINT_DEC 4, eax ; afiseaza prima multime
    NEWLINE
    PRINT_DEC 4, ebx ; afiseaza cea de-a doua multime
    NEWLINE

    ; TODO1: reuniunea a doua multimi
    or eax, ebx
    PRINT_DEC 4, eax
    NEWLINE

    ; TODO2: adaugarea unui element in multime
    mov eax, 768
    or ebx, eax
    ;PRINT_DEC 4, ebx

    ; TODO3: intersectia a doua multimi
    mov eax, 139 
    mov ebx, 169
    
    ; at first we need reunion
    mov edx, eax
    or edx, ebx ; save the reunion in edx
    
    ; then we need ~A&B amd ~B&A and substract them from reunion
    mov ecx, eax
    not ecx
    and ecx, ebx
    sub edx, ecx
    
    mov ecx, ebx
    not ecx
    and ecx, eax
    sub edx, ecx
    
    PRINT_STRING "Intersection is: "
    PRINT_DEC 4, edx
    NEWLINE
    

    ; TODO4: complementul unei multimi
    mov ecx, eax
    not ecx
    PRINT_STRING "Complementary of 139 is"
    PRINT_DEC 4, ecx
    NEWLINE


    ; TODO5: eliminarea unui element
    sub eax, 1
    PRINT_STRING "Eliminated 1 from eax set"
    PRINT_DEC 4, eax
    NEWLINE

    ; TODO6: diferenta de multimi EAX-EBX
    ; remaking A and B
    mov eax, 139 
    mov ebx, 169
    
    ; difference is ~B & A
    mov ecx, ebx
    not ecx
    and ecx, eax
    
    PRINT_STRING "Difference is:"
    PRINT_DEC 4, ecx    


    xor eax, eax
    ret
