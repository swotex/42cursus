global ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)()) rdi, rsi
ft_list_sort:
	sub rsp, 16 ; save t_list beggin and func
	mov QWORD [rsp], rdi ; save t_list
	; mov QWORD [rsp + 8], rsi ; save func
	mov r13, rsi ; save func
	mov rdx, [rdi] ; unreference list in rdx

	cmp rdx, 0 ; si list NULL
	je exit_sorted
	mov rbx, [rdx + 8]

	cmp rbx, 0 ; si list +1 NULL
	je exit_sorted

	jmp loop

	; rdx noeud 1 rbx noeud 2

	swap:
		mov r10, [rdx]
		mov r12, [rbx]
		mov [rdx], r12
		mov [rbx], r10

	set_start:
		mov rdx, QWORD [rsp]
		; mov rdx, [rdx]
		mov rbx, [rdx + 8]

	loop:
		cmp rbx, 0
		je exit_sorted

		mov rdi, [rdx]
		mov rsi, [rbx]
		push rdx
		push rbx
		call r13
		pop rbx
		pop rdx
		cmp rax, 0
		jg swap

		; next
		next:
			mov rdx, rbx
			mov rbx, [rdx + 8]
			jmp loop

	exit_sorted:
		mov rdi, [rsp]
		; mov rsi, [rsp + 8]
		mov rsi, r13
		add rsp, 16
		xor rax, rax
		ret
