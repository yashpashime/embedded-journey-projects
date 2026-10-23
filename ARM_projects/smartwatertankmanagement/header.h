#ifndef HEADER_H
#define HEADER_H

#include <LPC21xx.H>

typedef unsigned char u8;
typedef unsigned int u32;

/* LED, servo, buzzer and pump pin definitions */
#define ledred     (1<<17)
#define ledorange  (1<<18)
#define ledgreen   (1<<19)
#define servo      (1<<20)
#define buzzer     (1<<21)
#define relaypump  (1<<22)

/* Delay functions */
void delayms(u32 ms);
void delayus(u32 us);

/* ADC functions */
void adc_init(void);
unsigned int adc_read(int ch_num);

/* UART0 functions */
void uart0_init(unsigned int baud);
void uart_tx(unsigned char data);
unsigned char uart_rx(void);
void uart_tx_string(char *ptr);
void uartint(int num);
void uartfloat(float num);

/* UART1 functions */
void uart1_init(unsigned int baud);
void uart1_tx(unsigned char data);
unsigned char uart1_rx(void);
void uart1_tx_string(char *ptr);
void uart1int(int num);
void uart1float(float num);
void uart1_rx_string(char *s, int size);

/* LCD functions */
void lcdinit(void);
void lcdcmd(u32 cmd);
void lcddata(u8 data);
void lcdint(int num);
void lcdstring(char *p);

/* I2C functions */
void i2c_init(void);
void i2c_send(unsigned char sa, unsigned char mr,
              unsigned char data);
unsigned char i2c_receive(unsigned char sa,
                          unsigned char mr);

/* EEPROM functions */
void eeprom_i2c_init(void);
void eeprom_send(unsigned char sa,
                 unsigned short int mr,
                 unsigned char data);
unsigned char eeprom_receive(unsigned char sa,
                             unsigned short int mr);

/* External interrupt */
void configforeint0(void);
extern u8 flag1;

/* ESP-01 functions */
void esp_init(void);
void esp_send_data(int waterlevel, float temp, int pumpstatus);

/* Pump, buzzer, LED and servo functions */
void pump(int state);
void buzzercontrol(int state);
void ledset(int led_pin, int state);
void servoangle(int angle);
void valveopen(void);
void valveclose(void);

#endif
