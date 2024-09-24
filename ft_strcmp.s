global _ft_strcmp

_ft_strcmp:
    mov rcx, -1
    jmp loopcmp

loopcmp:
    inc rcx
    movzx rax, BYTE[rdi + rcx]
    movzx rbx, BYTE[rsi + rcx]
    test rax, rax
    jz exitcmp
    test rbx,rbx
    jz exitcmp
    cmp rax, rbx
    je loopcmp

exitcmp:
    sub rax, rbx
    ret
