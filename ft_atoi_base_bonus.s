; in C Piscine C4
global ft_atoi_base
global is_whitespace
global is_num
global find_char
global str_max_len
global get_decimal_number
global power
extern ft_strlen

; int power(int base, int exponent) rdi, rsi
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

; int get_decimal_number(char nb, base, exposant, lenBase) al, rsi, rdx, r9
get_decimal_number:
    push rdi
    mov rdi, rsi
    call find_char
    mov r11, rax
    mov rdi, r9
    push rsi
    mov rsi, rdx
    call power
    pop rsi
    pop rdi
    imul rax, r11
    ret


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
    cmp BYTE[rdi + r11], 0
    je return_not
    cmp BYTE[rdi + r11], al
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
    sub rsp, 32 ; reserve 4 int in stack (4 * 8 octet) aligned on 16
    mov qword [rsp], rax ; end of nbr str
    sub rax, rcx ; get max power
    mov qword [rsp + 8], rax ; power nbr str
    push rdi
    mov rdi, rsi
    call ft_strlen
    pop rdi
    mov qword [rsp + 16], rax ; size of base
    mov qword [rsp + 24], 0 ; result int


start_conversion:
    cmp rcx, qword [rsp]
    jg exit_test
    mov al, BYTE[rdi + rcx]
    mov rdx, qword [rsp + 8]
    mov r9, qword [rsp + 16]
    call get_decimal_number ; (char nb, base, exposant, lenBase) al, rsi, rdx, r9

    ; mov r9, qword [rsp + 24]
    ; add r9, rax
    ; mov qword [rsp + 24], r9
    add qword [rsp + 24], rax
   
    dec qword [rsp + 8]
    ; mov qword [rsp + 8], rdx
    inc rcx
    jmp start_conversion
    

exit_test:
    imul r10, qword [rsp + 24]
    mov rax, r10
    ; mov rax, qword [rsp + 24]
    add rsp, 32
    ret

return_err:
    pop rcx
    mov rax, 0
    ret
