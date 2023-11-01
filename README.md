# x86-asm

汇编命令：
>nasm -f elf hello.asm  // 编译  
>ld -m elf_i386 -s -o hello hello.o // 链接

## hello.asm
使用Intel X86汇编编写的Hello World代码。详情见注释。
知识点：使用 int 0x80系统调用，并且使用write相关寄存器

## loop.asm
输出1到100之间的ascii码的值。


## main.c
在c语言代码中使用内嵌汇编。


