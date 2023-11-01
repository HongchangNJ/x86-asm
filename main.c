#include <stdio.h>

char hello[] = "Hello, World!";

// AT&T风格
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

int main() {
    const char message[] = "Hello, World!\n";
    size_t message_len = sizeof(message) - 1;
    // Intel汇编风格
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

