global ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)()) rdi, rsi
ft_list_sort:
	push rbx
	push r12

	test rsi, rsi
	jz quit
	test rdi, rdi
	jz quit

	mov rbx, rsi ; save func
	mov r12, rdi ; save pointer list

	mov rdi, [rdi] ; unreference list
	test rdi, rdi
	jz quit
	jmp sort

	next:
		mov rdi, [rdi + 8]

	sort:
		cmp qword [rdi + 8], 0
		je quit

		mov rsi, [rdi + 8]
		xor rax, rax
		push rdi
		push rsi
		push rbx
		mov rdi, [rdi]		
		mov rsi, [rsi]
		call rbx ; call strcmp(lst->data, lst-next->data)
		pop rbx
		pop rsi
		pop rdi

		test ax, ax
		jle next


	swap:
		mov r10, [rdi]
		mov r11, [rsi]
		mov [rdi], r11
		mov [rsi], r10

		mov rdi, [r12]
		jmp sort

quit:
	pop r12
	pop rbx
	ret