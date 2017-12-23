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

#include "multiplexing.h"

#define TURN_OFF -1

volatile uint8_t _last_tube = TURN_OFF;
volatile uint8_t _last_digit = TURN_OFF;

#define _INIT(PIN) \
    PIN ## _DDR |= PIN

#define _SET_ON(PIN) \
    PIN ## _PORT |= PIN

#define _SET_OFF(PIN) \
    PIN ## _PORT &= ~(PIN)

inline void _set_off_tube(uint8_t tube)
{
    switch(tube)
    {
    case 0:
        _SET_OFF(NIXIE_0);
        break;
    case 1:
        _SET_OFF(NIXIE_1);
        break;
    case 2:
        _SET_OFF(NIXIE_2);
        break;
    case 3:
        _SET_OFF(NIXIE_3);
        break;
    case 4:
        _SET_OFF(NIXIE_4);
        break;
    }
    _last_tube = TURN_OFF;
}

inline void _set_on_tube(uint8_t tube)
{
    switch(tube)
    {
    case 0:
        _SET_ON(NIXIE_0);
        break;
    case 1:
        _SET_ON(NIXIE_1);
        break;
    case 2:
        _SET_ON(NIXIE_2);
        break;
    case 3:
        _SET_ON(NIXIE_3);
        break;
    case 4:
        _SET_ON(NIXIE_4);
        break;
    }
    _last_tube = tube;
}

inline void _set_off_digit(uint8_t digit)
{
    switch(digit)
    {
    case 0:
        _SET_OFF(DIGIT_0);
        break;
    case 1:
        _SET_OFF(DIGIT_1);
        break;
    case 2:
        _SET_OFF(DIGIT_2);
        break;
    case 3:
        _SET_OFF(DIGIT_3);
        break;
    case 4:
        _SET_OFF(DIGIT_4);
        break;
    case 5:
        _SET_OFF(DIGIT_5);
        break;
    case 6:
        _SET_OFF(DIGIT_6);
        break;
    case 7:
        _SET_OFF(DIGIT_7);
        break;
    case 8:
        _SET_OFF(DIGIT_8);
        break;
    case 9:
        _SET_OFF(DIGIT_9);
        break;
    }
    _last_digit = TURN_OFF;
}

inline void _set_on_digit(uint8_t digit)
{
    switch(digit)
    {
    case 0:
        _SET_ON(DIGIT_0);
        break;
    case 1:
        _SET_ON(DIGIT_1);
        break;
    case 2:
        _SET_ON(DIGIT_2);
        break;
    case 3:
        _SET_ON(DIGIT_3);
        break;
    case 4:
        _SET_ON(DIGIT_4);
        break;
    case 5:
        _SET_ON(DIGIT_5);
        break;
    case 6:
        _SET_ON(DIGIT_6);
        break;
    case 7:
        _SET_ON(DIGIT_7);
        break;
    case 8:
        _SET_ON(DIGIT_8);
        break;
    case 9:
        _SET_ON(DIGIT_9);
        break;
    }
    _last_digit = digit;
}

// Public functions

inline void multiplexing_init(void)
{
    _INIT(DIGIT_0);
    _INIT(DIGIT_1);
    _INIT(DIGIT_2);
    _INIT(DIGIT_3);
    _INIT(DIGIT_4);
    _INIT(DIGIT_5);
    _INIT(DIGIT_6);
    _INIT(DIGIT_7);
    _INIT(DIGIT_8);
    _INIT(DIGIT_9);

    _SET_OFF(DIGIT_0);
    _SET_OFF(DIGIT_1);
    _SET_OFF(DIGIT_2);
    _SET_OFF(DIGIT_3);
    _SET_OFF(DIGIT_4);
    _SET_OFF(DIGIT_5);
    _SET_OFF(DIGIT_6);
    _SET_OFF(DIGIT_7);
    _SET_OFF(DIGIT_8);
    _SET_OFF(DIGIT_9);

    _INIT(NIXIE_0);
    _INIT(NIXIE_1);
    _INIT(NIXIE_2);
    _INIT(NIXIE_3);
    _INIT(NIXIE_4);

    _SET_OFF(NIXIE_0);
    _SET_OFF(NIXIE_1);
    _SET_OFF(NIXIE_2);
    _SET_OFF(NIXIE_3);
    _SET_OFF(NIXIE_4);
}

inline void show_number(uint8_t tube, uint8_t digit)
{
    _set_off_tube(_last_tube);
    _set_off_digit(_last_digit);

    _set_on_digit(digit);
    _set_on_tube(tube);
}

inline void turn_off(void)
{
    _set_off_tube(_last_tube);
    _set_off_digit(_last_digit);
}
