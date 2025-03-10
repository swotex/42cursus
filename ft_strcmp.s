global ft_strcmp

ft_strcmp:
    mov rcx, -1
    push rbx

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
    pop rbx
    ret
