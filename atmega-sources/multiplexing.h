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

#ifndef MULTIPLEXING_H_
#define MULTIPLEXING_H_

#include <avr/io.h>

// nixie's digits control

#define DIGIT_0      (1 << PB1)
#define DIGIT_0_DDR  DDRB
#define DIGIT_0_PORT PORTB

#define DIGIT_1      (1 << PB2)
#define DIGIT_1_DDR  DDRB
#define DIGIT_1_PORT PORTB

#define DIGIT_2      (1 << PB3)
#define DIGIT_2_DDR  DDRB
#define DIGIT_2_PORT PORTB

#define DIGIT_3      (1 << PB4)
#define DIGIT_3_DDR  DDRB
#define DIGIT_3_PORT PORTB

#define DIGIT_4      (1 << PB5)
#define DIGIT_4_DDR  DDRB
#define DIGIT_4_PORT PORTB

#define DIGIT_5      (1 << PB0)
#define DIGIT_5_DDR  DDRB
#define DIGIT_5_PORT PORTB

#define DIGIT_6      (1 << PD7)
#define DIGIT_6_DDR  DDRD
#define DIGIT_6_PORT PORTD

#define DIGIT_7      (1 << PD6)
#define DIGIT_7_DDR  DDRD
#define DIGIT_7_PORT PORTD

#define DIGIT_8      (1 << PD5)
#define DIGIT_8_DDR  DDRD
#define DIGIT_8_PORT PORTD

#define DIGIT_9      (1 << PB7)
#define DIGIT_9_DDR  DDRB
#define DIGIT_9_PORT PORTB

// nixie's anodes control

#define NIXIE_0      (1 << PC0)
#define NIXIE_0_DDR  DDRC
#define NIXIE_0_PORT PORTC

#define NIXIE_1      (1 << PC1)
#define NIXIE_1_DDR  DDRC
#define NIXIE_1_PORT PORTC

#define NIXIE_2      (1 << PC2)
#define NIXIE_2_DDR  DDRC
#define NIXIE_2_PORT PORTC

#define NIXIE_3      (1 << PC3)
#define NIXIE_3_DDR  DDRC
#define NIXIE_3_PORT PORTC

#define NIXIE_4      (1 << PD4)
#define NIXIE_4_DDR  DDRD
#define NIXIE_4_PORT PORTD

// functions

void multiplexing_init(void);
void show_number(uint8_t tube, uint8_t digit);
void turn_off(void);

#endif /* MULTIPLEXING_H_ */
