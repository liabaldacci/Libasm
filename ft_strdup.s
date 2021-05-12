section	.text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	mov rax, 0
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call malloc
	pop rsi
	mov rdi, rax
	call ft_strcpy
	ret

