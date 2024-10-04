global ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)()) rdi, rsi
ft_list_sort:
	mov rdx, rsi
	; sub rsp, 16 ; begin and last
	mov rcx, rdi
	jmp loop

	switch_data:
		mov r10, qword [rdi]
		mov rdi, qword [rsi]
		mov rsi, r10
		mov rdi, rcx

	loop:
		mov rsi, [rdi + 8]
		cmp rsi, 0
		je return_sorted
		push rdi
		push rsi
		mov rdi, rdi
		mov rsi, [rsi]
		call rdx
		pop rsi
		pop rdi
		cmp rax, 0
		jg switch_data
		mov rdi, rsi
	jmp loop

	return_sorted:
		mov rdi, rcx
		ret
