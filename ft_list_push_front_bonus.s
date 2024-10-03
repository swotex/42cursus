; in C Piscine C12
global ft_list_push_front
extern malloc

; void ft_list_push_front(t_list **list, void *data) rdi, rsi
ft_list_push_front:
    push rdi
    push rsi
    mov rdi, 16
    call malloc wrt ..plt
    pop rsi
    pop rdi
    jz exit_error
    mov qword [rax], rsi
    mov rdx, [rdi]
    mov qword [rax + 8], rdx
    mov [rdi], rax
    mov rax, 0
    ret

    exit_error:
        mov rax, 0
        ret
