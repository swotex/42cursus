global ft_read

ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jl errorread
    ret

errorread:
    mov rax, -1
    ret