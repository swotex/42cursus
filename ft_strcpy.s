global ft_strcpy

ft_strcpy:
	mov rax, -1
	.loopcpy:
		inc rax
		mov cl, [rsi + rax]
		mov [rdi + rax], cl
		cmp BYTE[rsi + rax], 0
		jne .loopcpy
	mov rax, rdi
	ret
