global ft_write
extern __errno_location ; Find with : nm -D /usr/lib/x86_64-linux-gnu/libc.so.6 | grep errno_location

ft_write:
    mov rax, 1 ; Set syscall write
    syscall
    cmp rax, 0
    jl errorwrite
    ret

errorwrite:
    neg rax
    mov rdi, rax
    call __errno_location wrt ..plt ; Get memory location of errno
    mov [rax], rdi ; Add error code in errno
    mov rax, -1
    ret
