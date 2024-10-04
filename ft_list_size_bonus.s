global ft_list_size

; int ft_list_size(t_list *begin) rdi
ft_list_size:
	xor rax, rax
	mov rdx, rdi

	.loop:
		cmp rdx, 0
		je return_size
		inc rax
		mov rdx, [rdx + 8]
	jmp .loop

	return_size:
		ret
