global _ft_write

_ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl errorwrite
    ret

errorwrite:
    mov rax, -1
    ret
