/*
 * pin_definition.h
 *
 * Created: 02.08.2017 16:17:11
 *  Author: stas
 */ 


#ifndef PIN_DEFINITION_H_
#define PIN_DEFINITION_H_

#define LED1 				PD4
#define LED1_config()		DDRD |= ((1 << LED1))	// out
#define LED1_on()			PORTD |= (1 << LED1)
#define LED1_off()			PORTD &= ~(1 << LED1)
#define is_LED1()			(PIND & (1 << LED1))
#define LED1_blink() 		if (is_LED1())LED1_off(); else LED1_on()




#endif /* PIN_DEFINITION_H_ */