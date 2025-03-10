global ft_list_remove_if

%macro SAVE_CALL 0
    push r10
    push rdi
    push rsi
    push rdx
    push rcx
    push rbx
%endmacro

%macro RESTORE_CALL 0
    pop rbx
    pop rcx
    pop rdx
    pop rsi
    pop rdi
    pop r10
%endmacro

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
ft_list_remove_if:
    push rbx
    test rdi, rdi ; ** begin list
    jz exit
    test rsi, rsi ; * data to compare
    jz exit
    test rdx, rdx ; * cmp func
    jz exit
    test rcx, rcx ; free func
    jz exit

    mov r10, rdi ; Save beggin list pointer
    mov rdi, qword [rdi] ; Unref list (*lst)
    test rdi, rdi
    jz exit
    mov rbx, qword [rdi + 8] ; get second pointer (*lst->next)

    list_loop:
        ; -- Verify if pointer != null
        test rdi, rdi
        jz remove_first
        test rbx, rbx
        jz remove_first

        SAVE_CALL
        mov rdi, qword [rbx] ; select the second item
        call rdx ; Call (*cmp)(char* str, char* datacmp)
        RESTORE_CALL
        test rax, rax
        jz remove_item ; remove if equal

        set_next:
            mov rdi, rbx
            mov rbx, qword [rbx + 8]
        
        jmp list_loop


    remove_item:
        push qword [rbx + 8] ; save *secondPtr->next
        SAVE_CALL
        sub rsp, 8 ; Align stack
        mov rdi, [rbx] ; select the second item
        call rcx ; func free (secondPtr)
        add rsp, 8 ; restore stack
        RESTORE_CALL
        SAVE_CALL
        sub rsp, 8 ; Align stack
        mov rdi, rbx ; select the second item
        call rcx ; func free (secondPtr)
        add rsp, 8 ; restore stack
        RESTORE_CALL
        pop rbx
        mov qword [rdi + 8], rbx ; Set firstPtr->next = secondPtr->next
        jmp list_loop


    remove_first:
        mov rdi, [r10]
        mov rbx, qword [rdi + 8]

        SAVE_CALL
        mov rdi, qword [rdi]
        call rdx ; Call (*cmp)(char* str, char* datacmp)
        RESTORE_CALL
        test rax, rax
        jnz exit

        SAVE_CALL
        mov rdi, [rdi]
        sub rsp, 8 ; Align stack
        call rcx ; func free (secondPtr)
        add rsp, 8 ; restore stack
        RESTORE_CALL
        SAVE_CALL
        sub rsp, 8 ; Align stack
        call rcx ; func free (secondPtr)
        add rsp, 8 ; restore stack
        RESTORE_CALL

        mov [r10], rbx
        



    exit:
        pop rbx
        mov rdi, r10
        ret
