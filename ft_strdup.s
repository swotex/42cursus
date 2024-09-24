global _ft_strdup
extern malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
    ; rdi
    mov rsi, rdi
    call _ft_strlen
    inc rax
    mov rdi, rax
    call malloc
    cmp rax, 0
    je error_malloc
    mov rdi, rax
    call _ft_strcpy
    ret

error_malloc:
    mov rax, 0
