global ft_read
extern __errno_location ; nm -D /usr/lib/x86_64-linux-gnu/libc.so.6 | grep errno_location

ft_read:
    mov rax, 0 ; Set syscall to read
    syscall
    cmp rax, 0
    jl errorread
    ret

errorread:
    neg rax
    mov rdi, rax
    call __errno_location wrt ..plt ; Get errno memory location
    mov [rax], rdi ; Add error in errno
    mov rax, -1
    ret