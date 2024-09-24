global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    mov rsi, rdi
    call ft_strlen
    inc rax
    mov rdi, rax

    sub rsp, 8

    call malloc wrt ..plt

    add rsp, 8

    cmp rax, 0
    je error_malloc
    mov rdi, rax
    call ft_strcpy
    ret

error_malloc:
    mov rax, 0
    ret
