/*
 * USART1.c
 *
 * Created: 01/08/2023 07:00:53 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
    UART_init(9600);
	_delay_ms(300);//so that the LCD in recieve uc get initialized
	UART_send_string("ENG IBRAHIM");
	dm(1000);
		UART_send_char(0x01);
		_delay_ms(1000);
		UART_send_string("is the king!");
	
	while(1)
    {
        //TODO:: Please write your application code 
    }
}