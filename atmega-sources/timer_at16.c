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

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#define FREQUENCY 25
#define PRESCALE_FACTOR 256
#define OCR0_VALUE ((F_CPU/FREQUENCY/2/PRESCALE_FACTOR)-1)

extern void timer_interrupt(void);

ISR(TIMER0_COMP_vect)
{
	timer_interrupt();
}

void timer_init(void)
{
	cli();

	OCR0 = (uint8_t)OCR0_VALUE;
	TCNT0 = 0;

	TCCR0 |= (1 << WGM01); // CTC mode
	TCCR0 |= (1 << CS02); // Prescaler IO/256
	TIMSK |= (1 << OCIE0); // Enable interrupt

	sei();
}
