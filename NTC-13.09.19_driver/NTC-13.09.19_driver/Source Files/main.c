/*
 * NTC_13.c
 *
 * Created: 02.08.2017 15:27:20
 *  Author: stas
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <system.h>
#include <pin_definition.h>

int main(void)
{
    DDRB |= (1 << PB0);
    while (1)
    {
	    PORTB |=  (1 << PB0);
	    PORTB &= ~(1 << PB0);
    }
}