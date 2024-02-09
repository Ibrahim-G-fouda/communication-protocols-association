/*
 * USART_drives.c
 *
 * Created: 01/08/2023 07:05:55 م
 *  Author: handsa
 */ 
#define  F_CPU  8000000Ul
#include "std_macros1.h"
#include <util/delay.h>
#include <avr/io.h>
void UART_init(unsigned long baud)
{
	 unsigned short UBRR;
	 UBRR=(F_CPU/(16*baud)-1);//get the ubbr value for baud rate
	 UBRRH=(UBRR>>8);//here we write in ubrrh first and the 7th bit =0
	 UBRRL=UBRR;//baud rte init
	 set_bit(UCSRB,TXEN);//enable tx buffer
	  set_bit(UCSRB,RXEN);//enable rx buffer
	  UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);//here to get in UCSRC first we have to write 8 bit in same time and set the 7th bit to 1
	  //here we set the word size by 8 bit and one stop bit and no barity bit 
}
void UART_send_char(unsigned char data)
{
	while(read_bit(UCSRA,UDRE)==0);//in loop until tx buffer get empty
	UDR=data;
}
char UART_recieve_char(void)
{
while(read_bit(UCSRA,RXC)==0);//in loop until rx buffer recieve the data
return UDR;	
}
void UART_send_string(char*ptr)
{
	while(*ptr!=0)
	{
		UART_send_char(*ptr);
		ptr++;
		_delay_ms(100);
		
	}
	}