
#include <LPC21xx.H>
#include "header.h"

void delayms(u32 ms)
{
    T0PR = 15000 - 1;
    T0PC = 0;
    T0TC = 0;
    T0TCR = 1;

    while(T0TC < ms);

    T0TCR = 0;
}

void delayus(u32 us)
{
    T0PR = 14;
    T0PC = 0;
    T0TC = 0;
    T0TCR = 1;

    while(T0TC < us);

    T0TCR = 0;
}

