global ft_list_remove_if

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
ft_list_remove_if:
    mov rbx, [rdi]
    ; mov rsi, [rsi]
    ; mov r12, 0

    loop:
        cmp rbx, 0
        je exit

        mov rdi, rbx
        push rbx
        push rsi
        push rdx
        push rcx
        push r12
        mov rdi, [rdi]
        call rdx
        pop r12
        pop rcx
        pop rdx
        pop rsi
        pop rbx

        test rax, rax
        je remove

        ; add r12, 8
        mov rbx, [rbx + 8]
        jmp loop

    remove:
        mov rdi, rbx
        push rbx
        push rsi
        push rdx
        push rcx
        ; mov rdi, [rdi]
        call rcx
        pop rcx
        pop rdx
        pop rsi
        pop rbx

        ; add r12, 8
        mov rbx, [rbx + 8]
        jmp loop


exit:
    ret