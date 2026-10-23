
#include <LPC21xx.H>
#include "header.h"

void uart0_init(unsigned int baud)
{
    int pclk, result = 0;

    if(VPBDIV == 0X0)
        pclk = 15000000;
    else if(VPBDIV == 0X01)
        pclk = 60000000;
    if(VPBDIV == 0X02)
        pclk = 30000000;

    result = pclk/(16*baud);

    PINSEL0 |= 0x00000005;

    U0LCR = 0X83;
    U0DLL = result&0xFF;
    U0DLM = (result>>8)&0xFF;
    U0LCR = 0x03;
}

#define THRE ((U0LSR>>5)&1)

void uart_tx(unsigned char data)
{
    U0THR = data;
    while(THRE == 0);
}

#define RDR (U0LSR&1)

unsigned char uart_rx()
{
    while(RDR == 0);
    return U0RBR;
}

void uart_tx_string(char *ptr)
{
    while(*ptr != 0)
    {
        uart_tx(*ptr);
        ptr++;
    }
}

void uartint(int num)
{
    int a[10], i = 0, j;

    if(num == 0)
        uart_tx('0');

    if(num < 0)
    {
        num = -num;
        uart_tx('-');
    }

    while(num > 0)
    {
        a[i] = num%10 + 48;
        num = num/10;
        i++;
    }

    for(j = i-1; j >= 0; j--)
    {
        uart_tx(a[j]);
    }
}

void uartfloat(float num)
{
    int integer1 = (int)num;
    float num1 = (num-integer1)*1000;
    int integer2 = (int)(num1+0.5);

    if(num == 0)
    {
        uart_tx('0');
        return;
    }

    uartint(integer1);
    uart_tx('.');
    uartint(integer2);
}

