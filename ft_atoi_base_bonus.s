global ft_atoi_base
global is_whitespace
global is_num
global find_char
global str_max_len

; ##### str_max_len functin #####
; -- return end of str (in base) --
; int str_max_len(str, base)
str_max_len:
    mov r11, rcx
    jmp loop_str_max

loop_str_max:
    mov al, BYTE [rdi + r11]
    push rdi
    mov rdi, rsi
    push r11
    call find_char
    pop r11
    pop rdi
    cmp rax, -1
    je back_str_max
    inc r11
    jmp loop_str_max

back_str_max:
    dec r11
    mov rax, r11
    ret

; ##### find_char function #####
; -- return pos of char if find otherwise it return -1 --
; int findChar(str, char) on rdi, al
find_char:
    xor r11, r11
    jmp loop_find

loop_find:
    cmp BYTE[rdi, r11], 0
    je return_not
    cmp BYTE[rdi, r11], al
    je return_find
    inc r11
    jmp loop_find

return_find:
    mov rax, r11
    ret

return_not:
    mov rax, -1
    ret

; ##### is_num function #####
; -- return 1 if it's valid number otherwise 0 --
; int is_num(int) on al
is_num:
    cmp al, 48 ; test 0
    jl return_false
    cmp al, 57 ; test 9
    jg return_false
    mov rax, 1
    ret

return_false:
    mov rax, 0
    ret

; ##### is_whitespace function #####
; -- return 1 if it's whitespace otherwise 0 --
; int is_whitespace(char) on al
is_whitespace:
    cmp al, 32 ; test ' '
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

; ##### Start of atoi_base #####
; int ft_atoi_base(str, base)
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
    push rcx
    xor rcx, rcx
    jmp parse_base

inc_base:
    inc rcx

parse_base:
    cmp BYTE[rsi + rcx], 43 ; test '+'
    je return_err
    cmp BYTE[rsi + rcx], 45 ; test '-'
    je return_err
    mov al, BYTE[rsi + rcx]
    call is_whitespace
    cmp rax, 1
    je return_err
    cmp BYTE[rsi + rcx], 0 ; test '\0'
    je parse_to_twice
    jmp inc_base

parse_to_twice:
    cmp rcx, 1
    jle return_err
    xor rdx, rdx ; loop var 1 -> 0
    mov rcx, 1 ; loop var 2 -> 0
    jmp check_twice

next_char:
    inc rdx
    mov rcx, rdx
    inc rcx

check_twice:
    cmp BYTE[rsi, rdx], 0
    je get_true_src
    mov al, BYTE[rsi + rcx]
    cmp BYTE[rsi, rdx], al
    je return_err
    cmp al, 0
    je next_char
    inc rcx
    jmp check_twice

get_true_src:
    pop rcx
    call str_max_len
    sub rax, rcx
    ret


start_conversion:
    ; mov [r11, rdx], 0
    mov rax, r11
    ret

exit_test:
    pop rcx
    mov rax, 12
    ret

return_err:
    pop rcx
    mov rax, 0
    ret
