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

#include "config.h"

#if _PLATFORM == ATMEGA16

#include "twi.h"
#include <avr/io.h>

void twi_init(void)
{
	DDRC &= ~((1 << PC4) | (1 << PC5));
	TWBR = ((F_CPU/SCL_CLOCK) - 16)/2;
}

void twi_start(void)
{
	TWCR = (1 << TWINT) | ( 1<< TWSTA) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
}

void twi_stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	while((TWCR & (1 << TWSTO)));
}

void twi_write(uint8_t data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
}

uint8_t twi_read(ack_bit ack)
{

	TWCR = ack
	? ((1 << TWINT) | (1 << TWEN) | (1 << TWEA))
	: ((1 << TWINT) | (1 << TWEN)) ;
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}

#endif
