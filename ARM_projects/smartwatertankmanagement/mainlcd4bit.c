
#include <LPC21xx.H>
#include "header.h"

void lcdinit()
{
    IODIR1 = 0XFE<<16;

    lcdcmd(0x02);
    lcdcmd(0x28);
    lcdcmd(0x0e);
    lcdcmd(0x01);
}

void lcddata(u8 data)
{
    u8 temp;

    IOCLR1 = 0XFE<<16;
    temp = (data&0XF0)<<16;
    IOSET1 = temp;
    IOSET1 = 1<<17;
    IOCLR1 = 1<<18;
    IOSET1 = 1<<19;
    delayms(2);
    IOCLR1 = 1<<19;

    IOCLR1 = 0XFE<<16;
    temp = (data&0X0f)<<20;
    IOSET1 = temp;
    IOSET1 = 1<<17;
    IOCLR1 = 1<<18;
    IOSET1 = 1<<19;
    delayms(2);
    IOCLR1 = 1<<19;
}

void lcdcmd(u32 cmd)
{
    u32 temp;

    IOCLR1 = 0XFE<<16;
    temp = (cmd&0XF0)<<16;
    IOSET1 = temp;
    IOCLR1 = 1<<17;
    IOCLR1 = 1<<18;
    IOSET1 = 1<<19;
    delayms(2);
    IOCLR1 = 1<<19;

    IOCLR1 = 0XFE<<16;
    temp = (cmd&0x0f)<<20;
    IOSET1 = temp;
    IOCLR1 = 1<<17;
    IOCLR1 = 1<<18;
    IOSET1 = 1<<19;
    delayms(2);
    IOCLR1 = 1<<19;
}

void lcdint(int num)
{
    int a[10], i = 0;

    if(num == 0)
    {
        lcddata('0');
    }

    if(num < 0)
    {
        num = -num;
        lcddata('-');
    }

    while(num > 0)
    {
        a[i] = num%10 + 48;
        num = num/10;
        i++;
    }

    for(i = i-1; i >= 0; i--)
    {
        lcddata(a[i]);
    }
}

void lcdstring(char *p)
{
    while(*p != 0)
    {
        lcddata(*p);
        p++;
    }
}

