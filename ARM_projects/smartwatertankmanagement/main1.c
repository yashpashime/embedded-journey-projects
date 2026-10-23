#include <LPC21xx.H>
#include"header.h"
#define SW2 (1<<15)
extern u8 flag1;

int main()
{
    u8 h,m,s,d,month,y,wl,tp;
    u32 water,i;
    unsigned short int addr = 0;
    unsigned int record_size = 8;
    unsigned int eeprom_size = 65536;
    unsigned char c;
    float s1,lm35,temp,vout;
    int pumpstatus=0;

    //INITIALIZATIONS
    adc_init();
    uart0_init(9600);
    uart1_init(9600);
    lcdinit();
    esp_init();
    eeprom_i2c_init();
    i2c_init();
    configforeint0();
    // esp_init();
    delayms(2000);

    //gpio directions
    IODIR0|=(1<<17)|(1<<18)|(1<<19)|(1<<20)|(1<<22)|(1<<21);//LEDS
    //IODIR0|=(1<<20)|(1<<21);//VALVE(p0.20)+buzzer(p0.21)
    //water pump relay
    //IODIR0|=(1<<22);
    IODIR0&=~(1<<16);
    IODIR0&=~SW2;

    //DEFAULT STARTING STATES FOR ACTIVE LOW LEDS(ALL OFF)
    IOSET0|= (1<<17)|(1<<18)|(1<<19)|(1<<20)|(1<<21)|(1<<22);
    //IOCLR0=(1<<21);

    uart_tx_string("smart water tank management\r\n");
    uart_tx_string("\r\n-------------------------------\r\n");
    uart_tx_string("\r\nSystem:On\r\n");

    /*
    i2c_send(0xD0, 0x02, 0x23);//set hrs
    i2c_send(0xD0, 0x01, 0x20);//set mins
    i2c_send(0xD0, 0x00, 0x00);//set secs

    i2c_send(0xD0, 0x04, 0x14);//set DATE
    i2c_send(0xD0, 0x05, 0x10);//set MONTH
    i2c_send(0xD0, 0x06, 0x26);//set YEAR
    */

    while(1)
    {
        //----------------sensor code-----------------------------
        //water=0;
        //for(i=0;i<100;i++)
        water=adc_read(0);
        //water=water/100;
        s1=(water*100)/1023;

        lm35=0;
        for(i=0;i<100;i++)
            lm35+=adc_read(2);

        lm35=lm35/100;
        vout=(lm35*3.3)/1023;
        temp=vout*100;
        //tempscaled=(int)(temp*10);

        delayms(1000);

        if(flag1==1)
        {
            uart_tx_string("\r\nin Manual mode..\r\n");

            if(!(IOPIN0&SW2))
            {
                pump(1);
                valveopen();
                pumpstatus=1;
                uart_tx_string("Manual:pump on\r\n");
            }
            else
            {
                pump(0);
                valveclose();
                pumpstatus=0;
                uart_tx_string("Manual: pump off\r\n");
            }
        }
        else
        {
            uart_tx_string("in auto mode...\r\n");

            if(s1<=10)      //critical low
            {
                uart_tx_string("\r\nWater level(%): ");
                uartint(s1);
                uart_tx_string("\r\nCritical Low");
                uart_tx_string("\r\n");
                uart_tx_string("TEMP(degree celsius): ");
                uartfloat(temp);
                uart_tx_string("\r\n");

                pump(1);
                uart_tx_string("pump on 22...\r\n");
                valveopen();
                uart_tx_string("valve open 20...\r\n");
                buzzercontrol(1);//buzzer on
                uart_tx_string("buzzer on 21...\r\n");
                ledset(ledred,1);
                uart_tx_string("red led on 17...\r\n");
                ledset(ledorange,0);
                ledset(ledgreen,0);
                pumpstatus=1;
            }
            else if(s1>10 && s1<=30) //low
            {
                uart_tx_string("\r\nWater level(%): ");
                uartint(s1);
                uart_tx_string("\r\nLow");
                uart_tx_string("\r\n");
                uart_tx_string("TEMP(degree celsius): ");
                uartfloat(temp);
                uart_tx_string("\r\n");

                pump(1);
                uart_tx_string("pump on 22 ...\r\n");
                valveopen();
                uart_tx_string("valve open 20...\r\n");
                buzzercontrol(0);
                uart_tx_string("buzzer off 21...\r\n");//buzzer on
                ledset(ledred,0);
                ledset(ledorange,1);
                uart_tx_string("orange led on 18...\r\n");
                ledset(ledgreen,0);
                pumpstatus=1;
            }
            else if(s1>=90)
            {
                uart_tx_string("\r\nWater level(%): ");
                uartint(s1);
                uart_tx_string("\r\nTank Full");
                uart_tx_string("\r\n");
                uart_tx_string("TEMP(degree celsius): ");
                uartfloat(temp);
                uart_tx_string("\r\n");

                pump(0);
                uart_tx_string("pump off 22...\r\n");
                valveclose();
                uart_tx_string("valve close 20...\r\n");
                buzzercontrol(0);
                uart_tx_string("buzzer off 21...\r\n");//buzzer on
                ledset(ledred,0);
                ledset(ledorange,0);
                ledset(ledgreen,1);
                uart_tx_string("green led on 19...\r\n");
                pumpstatus=0;
            }
            else
            {
                uart_tx_string("\r\nWater level(%): ");
                uartint(s1);
                uart_tx_string("\r\nNORMAL");
                uart_tx_string("\r\n");
                uart_tx_string("TEMP(degree celsius): ");
                uartfloat(temp);
                uart_tx_string("\r\n");

                uart_tx_string("pump on till tank full 22...\r\n");
                buzzercontrol(0);//buzzer off
                uart_tx_string("buzzer off 21...\r\n");
                ledset(ledred,0);
                ledset(ledorange,0);
                ledset(ledgreen,1);
                uart_tx_string("green led on 19...\r\n");
            }

            delayms(1000);
        }

        //----------------------------------------------------------------------

        wl=(u8)s1;
        tp=temp;

        /*
        // --------------rtc--day----------------------
        d=i2c_receive(0xD1,0x04);//read date
        month=i2c_receive(0xD1,0x05);//read month
        y=i2c_receive(0xD1,0x06);//read year

        uart_tx_string("rtc date:");
        uart_tx((d/0x10)+48);
        uart_tx((d%0x10)+48);
        uart_tx('-');
        uart_tx((month/0x10)+48);
        uart_tx((month%0x10)+48);
        uart_tx('-');
        uart_tx_string("20");
        uart_tx((y/0x10)+48);
        uart_tx((y%0x10)+48);
        uart_tx_string("\r\n");
        //-----------------------------------------------

        // --------------rtc--time----------------------
        h=i2c_receive(0xD1,0x2);//read hours
        m=i2c_receive(0xD1,0x1);//read minutes
        s=i2c_receive(0xD1,0x0);//read seconds

        uart_tx_string("rtc time:");
        uart_tx((h/0x10)+48);
        uart_tx((h%0x10)+48);
        uart_tx(':');
        uart_tx((m/0x10)+48);
        uart_tx((m%0x10)+48);
        uart_tx(':');
        uart_tx((s/0x10)+48);
        uart_tx((s%0x10)+48);
        uart_tx_string("\r\n");
        */

        //-----------eeprom-------------------------
        uart_tx_string("eeprom storing dats.....\r\n");

        if(addr + record_size <= eeprom_size)
        {
            // Water level
            eeprom_send(0xA0, addr, wl);
            delayms(10);

            c = eeprom_receive(0xA1, addr);

            uart_tx_string("\r\n stored data in eeprom....\r\n ");
            uart_tx_string("\r\nWL = ");

            if(c >= 100)
            {
                uart_tx((c / 100) + 48);
                uart_tx(((c / 10) % 10) + 48);
                uart_tx((c % 10) + 48);
            }
            else if(c >= 10)
            {
                uart_tx((c / 10) + 48);
                uart_tx((c % 10) + 48);
            }
            else
            {
                uart_tx(c + 48);
            }

            uart_tx_string("%");
            addr++;

            //Temperature
            eeprom_send(0xA0, addr,tp);
            delayms(10);
            c = eeprom_receive(0xA1, addr);

            uart_tx_string("\r\n stored data in eeprom....\r\n ");
            uart_tx_string("\r\nTEMP(in C) = ");
            uartint(c);
            uart_tx_string(" Celsius\r\n");
            addr++;

            /*
            // Hour
            eeprom_send(0xA0, addr, h);
            delayms(10);
            c=eeprom_receive(0xA1, addr);

            uart_tx_string("\r\nHOUR = ");
            uart_tx((c / 0x10) + 48);
            uart_tx((c % 0x10) + 48);
            addr++;

            // Minute
            eeprom_send(0xA0, addr, m);
            delayms(10);
            c=eeprom_receive(0xA1, addr);

            uart_tx_string("\r\nMIN = ");
            uart_tx((c / 0x10) + 48);
            uart_tx((c % 0x10) + 48);
            addr++;

            // Second
            i2c_send(0xA0, addr, s);
            delayms(10);
            c=i2c_receive(0xA1, addr);

            uart_tx_string("\r\nSEC = ");
            uart_tx((c / 0x10) + 48);
            uart_tx((c % 0x10) + 48);
            addr++;

            // Date
            i2c_send(0xA0, addr, d);
            delayms(10);
            c=i2c_receive(0xA1, addr);

            uart_tx_string("\r\nDATE = ");
            uart_tx((c / 0x10) + 48);
            uart_tx((c % 0x10) + 48);
            addr++;

            // Month
            i2c_send(0xA0, addr, month);
            delayms(10);
            c=i2c_receive(0xA1, addr);

            uart_tx_string("\r\nMONTH = ");
            uart_tx((c / 0x10) + 48);
            uart_tx((c % 0x10) + 48);
            addr++;

            // Year
            eeprom_send(0xA0, addr, y);
            delayms(10);
            c=eeprom_receive(0xA1, addr);

            uart_tx_string("\r\nYEAR = ");
            uart_tx((c / 0x10) + 48);
            uart_tx((c % 0x10) + 48);
            addr++;
            */
        }
        else
        {
            uart_tx_string("\r\nEEPROM FULL\r\n");
        }

        esp_send_data(s1,temp,pumpstatus);

        //--------------eepromend-------------------------------
        uart_tx_string("\r\n--------------monitoring----\r\n");
        delayms(1000);
    }
}
