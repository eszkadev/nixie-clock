/*
 * Copyright (c) 2017 Szymon Kłos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "uart.h"
#include "ds1307.h"
#include "timer.h"
#include "multiplexing.h"

// LED of life
#define LED1        PD7
#define LED1_DDR    DDRD
#define LED1_PORT   PORTD

// print text over UART
#define PRINT(text) uart_puts((uint8_t*)text)

#define BUFFER_SIZE 32

#define TRUE 1
#define FALSE 0

volatile ds1307_time_t time;
volatile uint8_t time_dirty = TRUE;
volatile char buf[BUFFER_SIZE];
volatile uint8_t nixie = 0;

static uint8_t led = 0;

static inline void invert_led()
{
    led++;
    if(led % 2 == 0)
        LED1_PORT |= (1 << LED1);
    else
        LED1_PORT &= ~(1 << LED1);
}

// invalidate time
void timer_interrupt(void)
{
    time_dirty = TRUE;
}

// display multiplexing
void timer1_interrupt(void)
{
    switch(nixie)
    {
    case 0:
        nixie++;
        break;

    case 1:
        show_number(1, time.hours / 10);
        nixie++;
        break;

    case 2:
        show_number(2, time.hours % 10);
        nixie++;
        break;

    case 3:
        show_number(3, time.minutes / 10);
        nixie++;
        break;

    case 4:
        show_number(4, time.minutes % 10);
        nixie = 0;
        break;
    }
}

inline void time_setup(void)
{
    PRINT("SET DATE: ");
    uint8_t i = 0;

    do
    {
        buf[i] = uart_getc();
        if(buf[i])
        {
            uart_putc(buf[i]);

            if(buf[i] == '\n' || buf[i] == '\r')
                break;

            i++;
            buf[i] = 0;
        }
    }
    while(i < BUFFER_SIZE);

    if(i < BUFFER_SIZE)
        buf[i] = 0;

    ds1307_time_t new_time;
    if((sscanf((char*)buf, "%hhd:%hhd:%hhd",
            &(new_time.hours),
            &(new_time.minutes),
            &(new_time.seconds)) == 3)
        && new_time.hours < 24
        && new_time.minutes < 60
        && new_time.seconds < 60)
    {
        ds1307_set_time(&new_time);
        PRINT("\n\rOK\n\r");
    }
    else
    {
        PRINT("\n\rERROR\n\r");
    }
}

int main(void)
{
    // setup IO pins
    LED1_DDR |= (1 << LED1);
    LED1_PORT |= (1 << LED1);

    // initialize all peripherals
    multiplexing_init();
    uart_init();
    PRINT("UART OK\n\r");
#ifdef RTC
    ds1307_init();
    PRINT("RTC OK\n\r");
#endif
    timer_init();
    timer1_init();
    PRINT("TIMER OK\n\r");

#ifdef RTC
    // set current time - __TIME__
    set_time_from_string((ds1307_time_t*)&time, "11:22:33");
    ds1307_set_time((ds1307_time_t*)&time);
    PRINT("TIME SET OK\n\r");
#endif

    while(1)
    {
        // UART echo for testing purposes
        char c = uart_getc();
        if(c)
        {
            uart_putc(c);
            PRINT("\n\r");

            if(c == 's')
                time_setup();
        }

#ifdef RTC
        // read time from RTC
        if(time_dirty == TRUE)
        {
            time = ds1307_get_time();
            sprintf((char*)buf, "%02d:%02d:%02d\n\r", time.hours, time.minutes, time.seconds);
            PRINT(buf);
            time_dirty = FALSE;
        }
#endif

        if(time.seconds % 2 == 0)
            LED1_PORT |= (1 << LED1);
        else
            LED1_PORT &= ~(1 << LED1);
    }

    return 0;
}
