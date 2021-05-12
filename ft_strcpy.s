section	.text
	global ft_strcpy

ft_strcpy:
	mov rax, -1

loop:
	inc rax
	mov dl, byte [rsi + rax]
	mov byte [rdi + rax], dl
	cmp byte [rsi + rax], 0
	jne loop
	mov rax, rdi
	ret