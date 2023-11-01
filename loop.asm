section .data
    counter db 1  ; 用于存储计数器的值
    newline db 10
    newline_len equ $ - newline

section .text
global _start

_start:
    mov ecx, 100  ; 设置循环计数器为100


print_loop:
    push ecx
    ; 输出当前计数器的值
    mov eax, 4      ; 使用系统调用号4（write）
    mov ebx, 1      ; 文件描述符1（标准输出）
    mov ecx, counter ; 当前计数器的地址
    mov edx, 1      ; 输出一个字符
    int 0x80

    ; 输出空格
    mov eax, 4      ; 使用系统调用号4（write）
    mov ebx, 1      ; 文件描述符1（标准输出）
    mov ecx, 32     ; ASCII码32表示空格
    mov edx, 1      ; 输出一个字符
    int 0x80

    ; 递增计数器的值
    inc byte [counter]
    pop ecx

    loop print_loop  ; 循环，ECX自动减1，直到ECX为0

    ; 输出换行符
    mov eax, 4      ; 使用系统调用号4（write）
    mov ebx, 1      ; 文件描述符1（标准输出）
    mov ecx, newline ; 换行符的地址
    mov edx, newline_len  ; 换行符的长度
    int 0x80

    ; 退出程序
    mov eax, 1    ; 使用退出系统调用号1
    int 0x80      ; 调用Linux内核
