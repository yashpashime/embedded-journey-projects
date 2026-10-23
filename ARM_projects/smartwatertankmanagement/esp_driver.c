
#include "header.h"
#include <string.h>

#define WNAME "YOUR_WIFI_NAME"
#define WPASS "YOUR_WIFI_PASSWORD"

void esp_send_data(int waterlevel, float temp, int pumpstatus)
{
    char data[500], data_len[50];
    int len;

    uart_tx_string("starting sending data\r\n");

    sprintf(data,
            "GET /update?api_key=YOUR_THINGSPEAK_API_KEY&field1=%d&field2=%.2f&field3=%d HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n",
            waterlevel, temp, pumpstatus);

    len = strlen(data);

    sprintf(data_len, "AT+CIPSEND=%d\r\n", len);

    uart1_tx_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
    delayms(500);

    uart1_tx_string(data_len);
    delayms(500);

    uart1_tx_string(data);
    delayms(10000);

    uart_tx_string("Updated\r\n");
}

void esp_init()
{
    char s[10], c[40], wifi_details[150];

    sprintf(wifi_details, "AT+CWJAP=\"%s\",\"%s\"\r\n",
            WNAME, WPASS);

    uart_tx_string("Wifi Connecting...\r\n");
    lcdstring("Wifi Connecting");

    uart1_tx_string("AT\r\n");
    uart1_rx_string(s, 10);
    uart_tx_string(s);

    if(strstr(s, "AT\r\n\r\nOK") != 0)
        uart_tx_string("Device detected\r\n");

    delayms(500);

    uart1_tx_string("AT+CWMODE=1\r\n");
    delayms(500);

W:
    uart1_tx_string(wifi_details);
    delayms(5000);

    uart1_tx_string("AT+CWJAP?\r\n");
    uart1_rx_string(c, 32);

    if(strstr(c, WNAME) != 0)
        uart_tx_string("WIFI connect\r\n");
    else
    {
        uart_tx_string("WIFI not connect\r\n");
        goto W;
    }
}

