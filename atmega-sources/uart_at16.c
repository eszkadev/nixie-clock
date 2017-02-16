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

#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define UART_RX_BUF_SIZE 32

#define UART_DDR  DDRD
#define UART_PORT PORTD
#define UART_RX  PD0
#define UART_TX  PD1

#define BAUD 9600

volatile uint8_t uart_rx_buffer[UART_RX_BUF_SIZE];
volatile uint8_t uart_rx_counter;
volatile uint8_t* uart_rx_in;
volatile uint8_t* uart_rx_out;

ISR(USART_RXC_vect)
{
	uint8_t tmp = UDR;

	if(uart_rx_counter < UART_RX_BUF_SIZE)
	{
		*uart_rx_in = tmp;
		uart_rx_counter++;
		if(++uart_rx_in >= uart_rx_buffer + UART_RX_BUF_SIZE)
			uart_rx_in = uart_rx_buffer;
	}
}

void uart_init(void)
{
	// Setup IO pins
	UART_DDR |= (1 << UART_TX);
	UART_DDR &= ~(1 << UART_RX);
	UART_PORT |= (1 << UART_RX);

	#include <util/setbaud.h>

	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
	#ifdef USE_2X
		UCSRA |=  (1 << U2X);
	#else
		UCSRA &= ~(1 << U2X);
	#endif

	// Set frame format 8-N-1
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);

	// Enable RX and TX
	UCSRB = (1 << RXEN) | (1 << TXEN);

	// Disable interrupts
	cli();

	// Enable RX interrupt
	UCSRB |= (1 << RXCIE);

	uart_rx_in = uart_rx_out = uart_rx_buffer;
	uart_rx_counter = 0;

	// Enable interrupts
	sei();
}

void uart_putc(uint8_t c)
{
	while(!(UCSRA & (1 << UDRE)));

	UDR = c;

	UCSRA |= (1 << TXC);
	while(!(UCSRA & (1 << TXC)));
}

uint8_t uart_getc(void)
{
	if(!uart_rx_counter)
		return EMPTY_BUFFER;

	cli();
	uint8_t c = *uart_rx_out;

	uart_rx_counter--;
	if(++uart_rx_out >= uart_rx_buffer + UART_RX_BUF_SIZE)
		uart_rx_out = uart_rx_buffer;

	sei();

	return c;
}

void uart_puts(uint8_t* s)
{
	while(!(UCSRA & (1 << UDRE)));

	while(*s != 0)
	{
		UDR = *s++;
		UCSRA |= (1 << TXC);
		while(!(UCSRA & (1 << TXC)));
	}
}

void uart_put_bytes(uint8_t* tab, uint8_t size)
{
	while(!(UCSRA & (1 << UDRE)));

	while(size--)
	{
		UDR = *tab++;
		UCSRA |= (1 << TXC);
		while(!(UCSRA & (1 << TXC)));
	}
}
