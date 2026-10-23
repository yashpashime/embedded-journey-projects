
#include <LPC21xx.H>
#include "header.h"

void uart1_init(unsigned int baud)
{
    int pclk, result = 0;

    if(VPBDIV == 0X0)
        pclk = 15000000;
    else if(VPBDIV == 0X01)
        pclk = 60000000;
    if(VPBDIV == 0X02)
        pclk = 30000000;

    result = pclk/(16*baud);

    PINSEL0 |= 0x00050000;

    U1LCR = 0X83;
    U1DLL = result&0xFF;
    U1DLM = (result>>8)&0xFF;
    U1LCR = 0x03;
}

#define THRE1 ((U1LSR>>5)&1)

void uart1_tx(unsigned char data)
{
    U1THR = data;
    while(THRE1 == 0);
}

#define RDR1 (U1LSR&1)

unsigned char uart1_rx()
{
    while(RDR1 == 0);
    return U1RBR;
}

void uart1_tx_string(char *ptr)
{
    while(*ptr != 0)
    {
        uart1_tx(*ptr);
        ptr++;
    }
}

void uart1int(int num)
{
    int a[10], i = 0, j;

    if(num == 0)
        uart1_tx('0');

    if(num < 0)
    {
        num = -num;
        uart1_tx('-');
    }

    while(num > 0)
    {
        a[i] = num%10 + 48;
        num = num/10;
        i++;
    }

    for(j = i-1; j >= 0; j--)
    {
        uart1_tx(a[j]);
    }
}

void uart1float(float num)
{
    int integer1 = (int)num;
    float num1 = (num-integer1)*1000;
    int integer2 = (int)(num1+0.5);

    if(num == 0)
    {
        uart1_tx('0');
        return;
    }

    uart1int(integer1);
    uart1_tx('.');
    uart1int(integer2);
}

void uart1_rx_string(char *s, int size)
{
    int i = 0;

    for(i = 0; i < size; i++)
    {
        while(RDR1 == 0);
        s[i] = U1RBR;

        if(U1RBR == '\r')
            break;
    }

    s[i] = '\0';
}

