global _ft_strlen

_ft_strlen:
	mov rax, -1 ;init registre rax to 0
	jmp loop

loop:
	inc rax
	cmp BYTE[rdi + rax], 0
	jne loop
	ret
