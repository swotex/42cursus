global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    push rdi ; save str
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc wrt ..plt ; malloc strlen return
    pop rsi
    cmp rax, 0
    je error_malloc
    mov rdi, rax
    call ft_strcpy
    ret

error_malloc:
    mov rax, 0
    ret
