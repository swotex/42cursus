global ft_list_remove_if

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
ft_list_remove_if:
; ### Null testing ###
    test rdi, rdi ; ** begin list
    jz exit
    test rsi, rsi ; * data to compare
    jz exit
    test rdx, rdx ; * cmp func
    jz exit
    test rcx, rcx ; free func
    jz exit

; ### push 'callee-saved' in stack ###
    push rdi
    push rsi
    push rdx
    push rcx
    push r13
    push rbx

    mov r13, rdi ; save pointer
    mov rbx, [rdi] ; v1 -> lst start
    test rbx, rbx
    jz restore_registers
    mov rdi, [rbx + 8] ; v2 -> lst + 1
    mov r10, 0 ; v3 -> tmp to free


    list_loop:
        ; test if is end of lst
        test rdi, rdi
        jz restore_registers
        test rbx, rbx
        jz restore_registers

        push rdi
        push rsi
        ; push rbx
        push rcx
        push rdx
        mov rdi, [rdi]
        call rdx ; call cmp(v2, data)
        pop rdx
        pop rcx
        ; pop rbx
        pop rsi
        pop rdi
        test rax, rax
        jz remove_it

        set_next:
            mov rbx, rdi
            mov rdi, [rdi + 8]

        jmp list_loop

    remove_it:
        ; mov r10, [rdi + 8]
        ; push r10
        ; push rdi
        push qword [rdi + 8]
        mov rdi, [rdi]

        ; push rsi
        ; push rbx
        push rdx
        push rcx

        call rcx

        pop rcx
        pop rdx
        ; pop rbx
        ; pop rsi

        pop rdi
        jmp list_loop
    

    restore_registers:
        ; mov rdi, r13
        pop rbx
        pop r13
        pop rcx
        pop rdx
        pop rsi
        pop rdi

    exit:
        mov rax, 0
        ret















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
