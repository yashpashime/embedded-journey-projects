
#include <LPC21xx.H>
#include "header.h"

u8 flag1 = 0;

void eint0handler(void) __irq
{
    EXTINT = 1;
    flag1 ^= 1;
    VICVectAddr = 0;
}

void configforeint0(void)
{
    PINSEL1 |= 1;
    EXTMODE = 1;
    EXTPOLAR = 0;

    VICIntSelect = 0;
    VICVectCntl1 = 14 | (1<<5);
    VICVectAddr1 = (u32)eint0handler;
    VICIntEnable = (1<<14);
}

