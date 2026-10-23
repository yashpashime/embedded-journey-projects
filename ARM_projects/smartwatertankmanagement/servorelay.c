
#include <LPC21xx.H>
#include "header.h"

// Water pump control
void pump(int state)
{
    if(state)
        IOCLR0 = relaypump;  // Turn on pump
    else
        IOSET0 = relaypump;  // Turn off pump
}

// Buzzer control
void buzzercontrol(int state)
{
    if(state)
        IOCLR0 = buzzer;  // Turn on buzzer
    else
        IOSET0 = buzzer;  // Turn off buzzer
}

// LED control
void ledset(int led_pin, int state)
{
    if(state)
        IOCLR0 = led_pin;
    else
        IOSET0 = led_pin;
}

// Servo control
void servoangle(int angle)
{
    int i;
    unsigned int pulse;

    if(angle < 0)
        angle = 0;

    if(angle > 0)
        angle = 180;

    pulse = 1000 + ((unsigned int)angle * 1000)/180;

    for(i = 0; i < 15; i++)
    {
        IOSET0 = servo;  // Signal high
        delayus(pulse);

        IOCLR0 = servo;
        delayus(20000-pulse);  // Signal low
    }
}

void valveopen(void)
{
    servoangle(90);  // Rotate to open position
}

void valveclose(void)
{
    servoangle(0);   // Rotate to closed position
}

