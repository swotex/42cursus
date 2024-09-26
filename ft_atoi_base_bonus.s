global ft_atoi_base
global is_whitespace

is_whitespace:
    cmp al, 20 ; test ' '
    je return_true
    cmp al, 9 ; test '\t'
    je return_true
    cmp al, 10 ; test '\n'
    je return_true
    cmp al, 11 ; test '\v'
    je return_true
    cmp al, 12 ; test '\f'
    je return_true
    cmp al, 13 ; test '\r'
    je return_true

    mov rax, 0
    ret

return_true:
    mov rax, 1
    ret

ft_atoi_base:
    ; rdi -> char *str | rsi -> char *base
    mov rcx, -1
    mov r10, 1
    jmp loop_wspace_str

loop_wspace_str:
    inc rcx
    mov al, BYTE[rdi + rcx]
    call is_whitespace
    cmp rax, 1
    je loop_wspace_str
    jmp loop_sign_str

change_sign:
    neg r10

inc_str:
    inc rcx

loop_sign_str:
    cmp BYTE[rdi + rcx], 43 ; test '+'
    je inc_str
    cmp BYTE[rdi + rcx], 45 ; test '-'
    je change_sign
    jmp exit_test

exit_test:
    mov rax, r10
    ret
