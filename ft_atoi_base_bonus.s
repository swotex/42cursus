global ft_atoi_base
extern ft_strlen

; ##### Function power #####
; -- int power(int base, int exponent) -> rdi, rsi --
; return power of
power:
    mov rax, 1 ; init rax 1
    test rsi, rsi ; test exponent 0
    jz .done
    .power_loop:
        imul rax, rdi ; RAX *= RDI
        dec rsi ; decrement exponent
    jnz .power_loop
    
    .done:
        ret

; ##### Function get_decimal_number #####
; -- int get_decimal_number(char nb, char *base, int exposant, int lenBase) -> rdi, rsi, rdx, rcx --
; return converted number in decimal by exponent (pos)
get_decimal_number:
    push rdi
    push rsi

    mov r11, rdi
    mov rdi, rsi
    mov rsi, r11
    push rcx

    call find_by_char
    mov r11, rax

    pop rcx
    mov rdi, rcx
    mov rsi, rdx
    push rcx

    call power

    pop rcx
    pop rsi
    pop rdi

    imul rax, r11
    ret


; ##### Function find_by_char #####
; int find_by_char(char *str, char item) -> rdi, rsi
; return pos of item otherwise return -1
find_by_char:
    xor rcx, rcx

    loop_find:
        cmp BYTE[rdi + rcx], 0
        je return_not_found
        mov rax, rsi
        cmp BYTE[rdi + rcx], al
        je return_find
        inc rcx
        jmp loop_find

    return_find:
        mov rax, rcx
        ret

    return_not_found:
        mov rax, -1
        ret


; ##### Function get_real_len_str #####
; -- int get_real_len_str(char *str, char *base) -> rdi, rsi --
; get str+x and base, after, verify the len of str by find str[i] is in base
get_real_len_str:
    push rcx
    xor rcx, rcx

    loop_str_max:
        push rdi
        push rsi
        push rcx
        mov r11, rdi ; save str
        mov rdi, rsi ; set arg1 to base
        movzx rsi, BYTE[r11 + rcx] ; set arg2 to str[i]
        call find_by_char
        pop rcx
        pop rsi
        pop rdi
        cmp rax, -1
        je return_real_len
        inc rcx
        jmp loop_str_max

    return_real_len:
        dec rcx
        mov rax, rcx
        pop rcx
        ret

; ##### is_whitespace function #####
; -- int is_whitespace(char) -> rdi --
; return 1 if it's whitespace otherwise 0
is_whitespace:
    cmp rdi, 32 ; test ' '
    je return_true
    cmp rdi, 9 ; test '\t'
    je return_true
    cmp rdi, 10 ; test '\n'
    je return_true
    cmp rdi, 11 ; test '\v'
    je return_true
    cmp rdi, 12 ; test '\f'
    je return_true
    cmp rdi, 13 ; test '\r'
    je return_true

    mov rax, 0
    ret

return_true:
    mov rax, 1
    ret


; ########## Function atoi_base ##########
; -- int ft_atoi_base(char *str, char *base) -> rdi, rsi --
ft_atoi_base:
    test rdi, rdi
    jz exit
    test rsi, rsi
    jz exit

    mov rcx, -1
    mov r10, 1 ; Final sign of str

    parse_str:
        skip_white_space_str:
            inc rcx
            push rdi
            movzx rdi, BYTE[rdi + rcx]
            call is_whitespace
            pop rdi
            cmp rax, 1
            je skip_white_space_str
            jmp parse_sign_str

        change_sign:
            neg r10
        inc_str:
            inc rcx
        parse_sign_str:
            cmp BYTE[rdi + rcx], 43 ; test '+'
            je inc_str
            cmp BYTE[rdi + rcx], 45 ; test '-'
            je change_sign
            push rcx ; save start of str
            xor rcx, rcx ; set to 0
            jmp parse_sign_wspace_base

    parse_base:
        inc_base:
            inc rcx
        parse_sign_wspace_base:
            cmp BYTE[rsi + rcx], 43 ; test '+'
            je return_err
            cmp BYTE[rsi + rcx], 45 ; test '-'
            je return_err
            push rdi
            movzx rdi, BYTE[rsi + rcx]
            call is_whitespace ; test white-space
            pop rdi
            cmp rax, 1
            je return_err
            cmp BYTE[rsi + rcx], 0 ; test '\0'
            je parse_twice
            jmp inc_base

        parse_twice:
            cmp rcx, 1
            jle return_err ; error if base len == 1
            xor rdx, rdx ; set var 1 -> 0
            mov rcx, 1 ; set var 2 -> 1
            jmp check_twice

            next_char:
                inc rdx
                mov rcx, rdx
                inc rcx

            check_twice:
                cmp BYTE[rsi, rdx], 0 ; if (base + var1 == 0)
                je setup_var_convert
                mov al, BYTE[rsi + rcx] ; get base + var2
                cmp BYTE[rsi, rdx], al ; cmp (base + var1) == (base + var2)
                je return_err
                cmp al, 0
                je next_char
                inc rcx
                jmp check_twice

    base_convertion:
        setup_var_convert:
            pop rcx

            call get_real_len_str
            sub rsp, 32 ; reserve 4 int in stack (4 * 8 octet) aligned on 16
            mov qword [rsp], rax ; end of number str
            sub rax, rcx ; add start size
            mov qword [rsp + 8], rax ; power nbr str
            push rdi
            mov rdi, rsi
            call ft_strlen
            pop rdi
            mov qword [rsp + 16], rax ; size of base
            mov qword [rsp + 24], 0 ; result int

            convert_str:
                cmp rcx, qword [rsp] ; if rcx ==  end of str (can be convert)
                jg exit_success

                push rdi
                push rsi
                push rdx
                push rcx

                movzx rdi, BYTE[rdi + rcx]
                mov rdx, qword [rsp + 40]
                mov rcx, qword [rsp + 48]

                call get_decimal_number ; (char nb, base, exposant, lenBase) rdi (di), rsi, rdx, rcx

                pop rcx
                pop rdx
                pop rsi
                pop rdi

                add qword [rsp + 24], rax ; add result of get_decimal_number in final number
                dec qword [rsp + 8] ; decrement power

                inc rcx
                jmp convert_str


exit_success:
    imul r10, qword [rsp + 24]
    mov rax, r10
    add rsp, 32
    ret

return_err:
    pop rcx
exit:
    xor rax, rax ; set to 0
    ret