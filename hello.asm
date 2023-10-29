section .data
    hello db 'Hello, World!',0  ; 存储要打印的字符串，以null结尾

section .text
    global _start

_start:
    ; 调用Linux系统调用来写 'Hello, World!' 到标准输出（文件描述符 1）
    mov eax, 4       ; 4表示sys_write系统调用
    mov ebx, 1       ; 文件描述符 1（标准输出）
    mov ecx, hello   ; 存储要写的字符串的地址
    mov edx, 13      ; 字符串的长度
    int 0x80         ; 执行系统调用

    ; 退出程序并返回退出码 0
    mov eax, 1       ; 1表示sys_exit系统调用
    xor ebx, ebx     ; 退出码为0
    int 0x80         ; 执行系统调用

