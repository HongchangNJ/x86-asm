#include <stdio.h>

char hello[] = "Hello, World!";
//void helloWorld() {
//    __asm__ (
//            "movl $4, %%eax\n"        // sys_write
//            "movl $1, %%ebx\n"        // file descriptor (stdout)
//            "movl $hello, %%ecx\n"    // pointer to the message
//            "movl $13, %%edx\n"       // message length
//            "int $0x80\n"             // make a system call
//
//            // exit(0)
//            "movl $1, %%eax\n"        // sys_exit
//            "movl $0, %%ebx\n"        // exit status
//            "int $0x80\n"             // make a system call"
//            :
//            : "r"("Hello, World!---")
//            );
//}

/**
 *     asm volatile (
            "mov $1, %%rax\n"           // sys_write
            "mov $1, %%rdi\n"           // 文件描述符 (stdout)
            "mov %0, %%rsi\n"           // 消息的地址
            "mov %1, %%rdx\n"           // 消息的长度
            "syscall\n"
            :
            : "r" (message), "r" (message_len)
            : "%rax", "%rdi", "%rsi", "%rdx"
            );
 * @return
 */

/**
    __asm__ (
            "mov rax, 1\n"          // sys_write
            "mov rdi, 1\n"          // file descriptor (stdout)
            "mov rsi, %0\n"      // pointer to the message
            "mov rdx, %1\n"         // message length
            "syscall\n"            // make a system call"

            // exit(0)
            "mov rax, 60\n"          // sys_exit
            "mov rdi, 0\n"          // exit status
            "syscall\n"            // make a system call"
            :
            : "r" (message), "r" (message_len)
            );
 */

int main() {
    const char message[] = "Hello, World!\n";
    size_t message_len = sizeof(message) - 1;
    asm volatile (
            "mov eax, 1\n"          // sys_write
            "mov edi, 1\n"          // file descriptor (stdout)
            "mov rsi, %0\n"      // pointer to the message
            "mov rdx, %1\n"         // message length
            "syscall\n"            // make a system call"

            "mov eax, 60\n"          // sys_exit
            "mov edi, 0\n"          // exit status
            "syscall\n"            // make a system call"

            :
            : "r" (message), "r" (message_len)
            : "eax", "edi", "rsi", "rdx"
            );

    return 0;
}

