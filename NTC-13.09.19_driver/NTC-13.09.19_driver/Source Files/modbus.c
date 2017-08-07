/*
 * modbus.c
 *
 * Created: 03.08.2017 11:28:23
 *  Author: stas
 */ 
#include <avr/io.h>
#include <modbus.h>
#include <system.h>

void modbus_init()
{
	//Config BAUD_RATE
	UBRRL = UBRRL_VALUE;
	UBRRH = UBRRL_VALUE >> 8;
#ifdef URSEL
	UCSRC = 1 << URSEL | UCSRC_DATA_BITS | UCSRC_PARITY | UCSRC_STOP_BITS;
#else
	UCSRC = UCSRC_DATA_BITS | UCSRC_PARITY | UCSRC_STOP_BITS;
#endif
	//Enable TXEN pin
	RS485_PIN_DIRECTION_SET_OUT;
	RS485_SET_RX;
	
	UART_TX_ENABLE;
	UART_RX_ENABLE;
	UART_ENABLE_RX_INT;
	
	float period = 10.0f/UART_SPEED*3.5f;
	//set_mb_silence_timer_period_s(period);
}

