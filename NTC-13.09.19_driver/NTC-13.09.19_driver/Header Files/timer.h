/*
 * timer.h
 *
 * Created: 03.08.2017 16:37:59
 *  Author: stas
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>

#ifdef TCCR0B
	#define TCCR0 TCCR0B
#endif

#ifdef TIMSK0
	#define TIMSK TIMSK0
#endif

#ifdef TIFR0
	#define TIFR TIFR0
#endif

//Timer update
#define	T35_TIMER		220

//Timer setup
#define T35_SETUP 			TCCR0 |= (1<<CS00) | (1<<CS02) 		//source : CLK, prescaler: 1024
#define	T35_I_TIMER_ENABLE	TIMSK |= (1<< TOIE0)            	//turn on interrupt from overflow timer
#define	T35_I_TIMER_DISABLE	TIMSK &= ~(1<< TOIE0)           	//turn off interrupt from overflow timer
#define T35_TOV0_RESET		TIFR = (1<<TOV0)					//reset timer
#define T35_TIMER_RESET 	TCNT0 = T35_TIMER

void timer_init();

#endif /* TIMER_H_ */