/*
 * USART2.c
 *
 * Created: 02/08/2023 12:14:25 ص
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
 char x=0;
  lcd_init();
  UART_init(9600);
   for (x=0;x<11;x++)
   {
	   lcd_send_char(UART_recieve_char());
	   
   }
   lcd_send_cmd(UART_recieve_char());
    for (x=0;x<12;x++)
    {
	    lcd_send_char(UART_recieve_char());
	    
    }
  
    while(1)
    {
      
	 

    }
}