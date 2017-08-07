/*
 * modbus.h
 *
 * Created: 03.08.2017 11:27:48
 *  Author: stas
 */ 


#ifndef MODBUS_H_
#define MODBUS_H_

// UART parameters
#define UART_SPEED						19200
#define UART_DATA_BITS 					8
#define UART_PARITY  					'n'
#define UART_STOP_BITS 					1

// RS485 pin and port configuration
#define RS485_PORT_DIRECTION			PORTD
#define RS485_DDR_PORT_DIRECTION		DDRD
#define RS485_PIN_DIRECTION 			(1<<PD3)
#define	RS485_PIN_DIRECTION_SET_OUT 	RS485_DDR_PORT_DIRECTION |= RS485_PIN_DIRECTION

// RS485 macros
#define RS485_SET_TX					RS485_PORT_DIRECTION |= RS485_PIN_DIRECTION
#define RS485_SET_RX					RS485_PORT_DIRECTION &= ~RS485_PIN_DIRECTION

//Modbus slave address
#define MB_ADDRESS 0x02

//UART RX interrupt
#define UART_ENABLE_RX_INT				UCSRB |= (1 << RXCIE)
#define UART_DISABLE_RX_INT				UCSRB &= ~(1 << RXCIE)

//UART TX interrupt
#define UART_ENABLE_TX_INT				UCSRB |= (1 << UDRIE)
#define UART_DISABLE_TX_INT				UCSRB &= ~(1 << UDRIE)

//UART RX config
#define UART_RX_ENABLE					UCSRB |= (1 << RXEN)
#define UART_RX_DISABLE					UCSRB &= ~(1 << RXEN)

//UART TX config
#define UART_TX_ENABLE					UCSRB |= (1 << TXEN)
#define UART_TX_DISABLE					UCSRB &= ~(1 << RXEN)

//value of BAUD Rate for UBRRL register
#define UBRRL_VALUE	( ( F_CPU ) / ( ( UART_SPEED ) * 16UL ) - 1 )

//set configurations bits for UART
#if UART_DATA_BITS == 5
	#define UCSRB_DATA_BITS ( 0 << UCSZ2 )
	#define UCSRC_DATA_BITS ( 0 << UCSZ1 | 0 << UCSZ0 )
#elif UART_DATA_BITS == 6
	#define UCSRB_DATA_BITS ( 0 << UCSZ2 )
	#define UCSRC_DATA_BITS ( 0 << UCSZ1 | 1 << UCSZ0 )
#elif UART_DATA_BITS == 7
	#define UCSRB_DATA_BITS ( 0 << UCSZ2 )
	#define UCSRC_DATA_BITS ( 1 << UCSZ1 | 0 << UCSZ0 )
#elif UART_DATA_BITS == 8
	#define UCSRB_DATA_BITS ( 0 << UCSZ2 )
	#define UCSRC_DATA_BITS ( 1 << UCSZ1 | 1 << UCSZ0 )
#elif UART_DATA_BITS == 9
	#define UCSRB_DATA_BITS ( 1 << UCSZ2 )
	#define UCSRC_DATA_BITS ( 1 << UCSZ1 | 1 << UCSZ0 )
#endif

#if UART_PARITY == 'n'
	#define UCSRC_PARITY ( 0 << UPM1 | 0 << UPM0 )
#elif UART_PARITY == 'e'
	#define UCSRC_PARITY ( 1 << UPM1 | 0 << UPM0 )
#elif UART_PARITY == 'o'
	#define UCSRC_PARITY ( 1 << UPM1 | 1 << UPM0 )
#endif

#if UART_STOP_BITS == 1
	#define UCSRC_STOP_BITS ( 0 << USBS )
#elif UART_STOP_BITS == 2
	#define UCSRC_STOP_BITS ( 1 << USBS )
#endif


void modbus_init();



#endif /* MODBUS_H_ */