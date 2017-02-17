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

#include "twi.h"
#include "ds1307.h"

#define DS1307W 0xD0
#define DS1307R 0xD1

#define SECONDS_REG 0x00

uint8_t from_BCD(uint8_t x)
{
	return (x & 0x0F) + 10*((x >> 4) & 0x0F);
}

uint8_t to_BCD(uint8_t x)
{
	return (x % 10) + (((x / 10) % 10) << 4);
}

void ds1307_init(void)
{
	twi_init();

	// disable clock halt
	uint8_t seconds = ds1307_get_seconds();
	ds1307_transmit(SECONDS_REG, seconds & (~(1<<7)));
}

uint8_t ds1307_get_seconds(void)
{
	uint8_t seconds = ds1307_receive(SECONDS_REG);
	return from_BCD(seconds);
}

void ds1307_transmit(uint8_t address, uint8_t value)
{
	twi_start();
	twi_write(DS1307W);
	twi_write(address);
	twi_write(value);
	twi_stop();
}

uint8_t ds1307_receive(uint8_t address)
{
	twi_start();
	twi_write(DS1307W);
	twi_write(address);
	twi_start();
	twi_write(DS1307R);

	uint16_t ret = twi_read(NOACK);
	twi_stop();

	return ret;
}

ds1307_time_t ds1307_get_time(void)
{
	ds1307_time_t time;

	twi_start();
	twi_write(DS1307W);
	twi_write(SECONDS_REG);
	twi_start();
	twi_write(DS1307R);

	time.seconds = from_BCD(twi_read(ACK) & 0x3F);
	time.minutes = from_BCD(twi_read(ACK));
	time.hours = from_BCD(twi_read(ACK));
	time.day_of_week = twi_read(ACK);
	time.day = from_BCD(twi_read(ACK));
	time.month = from_BCD(twi_read(ACK));
	time.year = from_BCD(twi_read(NOACK));

	twi_stop();

	return time;
}
