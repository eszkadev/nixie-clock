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

// LED of life
#define LED1 PD7

// nixie's digits control
#define DIGIT1 PD6
#define DIGIT2 PD5

// nixie's anodes control
#define NIXIE1 PD4
#define NIXIE2 PD3

// print text over UART
#define PRINT(text) uart_puts((uint8_t*)text)

#define TRUE 1
#define FALSE 0

ds1307_time_t time;
volatile uint8_t time_dirty = TRUE;

void timer_interrupt(void)
{
	time_dirty = TRUE;
}

int main(void)
{
	char buf[32];

	// setup IO pins

	DDRD  |= (1 << LED1)
			| (1 << DIGIT2)
			| (1 << DIGIT1)
			| (1 << NIXIE1)
			| (1 << NIXIE2);

	PORTD |= (1 << DIGIT1)
			| (1 << NIXIE1);

	PORTD &= ~((1 << DIGIT2)
			| (1 << NIXIE2));

	// initialize all peripherals

	uart_init();
	PRINT("UART OK\n\r");
	ds1307_init();
	PRINT("RTC OK\n\r");
	timer_init();
	PRINT("TIMER OK\n\r");

	// set current time

	set_time_from_string(&time, __TIME__);
	ds1307_set_time(time);
	PRINT("TIME SET OK\n\r");

	int counter = 0;
	while(1)
	{
		PORTD ^=(1<<LED1);
		PORTD ^=(1<<DIGIT1);
		PORTD ^=(1<<DIGIT2);

		counter++;
		if(counter == 100)
		{
			PORTD ^=(1<<DIGIT1);
			PORTD ^=(1<<DIGIT2);
			counter = 0;
		}

		PORTD ^=(1<<NIXIE1);
		PORTD ^=(1<<NIXIE2);

		// UART echo for testing purposes

		char c = uart_getc();
		if(c)
		{
			uart_putc(c);
			PRINT("\n\r");
		}

		// read time from RTC

		if(time_dirty == TRUE)
		{
			time = ds1307_get_time();
			sprintf(buf, "%d:%d:%d\n\r", time.hours, time.minutes, time.seconds);
			PRINT(buf);
			time_dirty = FALSE;
		}

		_delay_ms(10);
	}

	return 0;
}
