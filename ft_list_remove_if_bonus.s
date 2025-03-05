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









; global ft_list_remove_if

; %macro SAVE_CALL 0
;     push rdi
;     push rsi
;     push rdx
;     push rcx
;     push r13
; %endmacro

; %macro RESTORE_CALL 0
;     pop r13
;     pop rcx
;     pop rdx
;     pop rsi
;     pop rdi
; %endmacro
; ; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
; ft_list_remove_if:
; ; ### Null testing ###
;     test rdi, rdi ; ** begin list
;     jz exit
;     test rsi, rsi ; * data to compare
;     jz exit
;     test rdx, rdx ; * cmp func
;     jz exit
;     test rcx, rcx ; free func
;     jz exit

; ; ### push 'callee-saved' in stack ###
;     ; push rdi
;     push rsi
;     push rdx
;     push rcx
;     push r13
;     push rbx

;     mov r13, rdi ; save pointer
;     mov rbx, [rdi] ; v1 -> lst start
;     test rbx, rbx
;     jz restore_registers
;     mov rdi, [rbx + 8] ; v2 -> lst + 1
;     ; mov r10, 0 ; v3 -> tmp to free


;     list_loop:
;         ; test if is end of lst
;         test rdi, rdi
;         jz remove_first
;         test rbx, rbx
;         jz remove_first

        
;         SAVE_CALL
;         mov rdi, [rdi]
;         call rdx ; call cmp(v2, data)
;         RESTORE_CALL

;         test rax, rax
;         jz remove_it

;         set_next:
;             mov rbx, rdi
;             mov rdi, [rdi + 8]

;         jmp list_loop

;     remove_it:
;         ; mov r10, [rdi + 8]
;         ; push r10
;         ; push rdi
;         push qword [rdi + 8]
;         ; mov rdi, [rdi]

;         ; push rsi
;         ; push rbx
;         ; push rdx
;         ; push rcx

;         SAVE_CALL

;         call rcx

;         RESTORE_CALL

;         ; pop rcx
;         ; pop rdx
;         ; pop rbx
;         ; pop rsi

;         pop rdi
;         ; mov [rbx + 8], rdi
;         jmp list_loop

    
;     remove_first:
;         mov rdi, r13
;         mov rdi, [rdi]
;         test rdi, rdi
;         jz restore_registers

;         SAVE_CALL
;         mov rdi, [rdi]
;         call rdx ; call cmp(lst, data)
;         RESTORE_CALL

;         test rax, rax
;         jnz restore_registers

;         ; mov rdi, [rdi]
;         ; lea r13, [rdi + 8]
;         push qword [rdi + 8]

;         SAVE_CALL

;         call rcx

;         RESTORE_CALL
;         ; mov rdi, [r13]
;         pop rdi
;         mov [r13], rdi
;         mov rdi, r13



;     restore_registers:
;         ; mov rdi, r13
;         pop rbx
;         pop r13
;         pop rcx
;         pop rdx
;         pop rsi
;         pop rdi

;     exit:
;         mov rax, 0
;         ret















; old code :




; global ft_list_remove_if

; ; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
; ft_list_remove_if:
;     mov rbx, [rdi]
;     ; mov rsi, [rsi]
;     ; mov r12, 0

;     loop:
;         cmp rbx, 0
;         je exit

;         mov rdi, rbx
;         push rbx
;         push rsi
;         push rdx
;         push rcx
;         push r12
;         mov rdi, [rdi]
;         call rdx
;         pop r12
;         pop rcx
;         pop rdx
;         pop rsi
;         pop rbx

;         test rax, rax
;         je remove

;         ; add r12, 8
;         mov rbx, [rbx + 8]
;         jmp loop

;     remove:
;         mov rdi, rbx
;         push rbx
;         push rsi
;         push rdx
;         push rcx
;         ; mov rdi, [rdi]
;         call rcx
;         pop rcx
;         pop rdx
;         pop rsi
;         pop rbx

;         ; add r12, 8
;         mov rbx, [rbx + 8]
;         jmp loop


; exit:
;     ret
