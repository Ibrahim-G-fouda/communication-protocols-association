/*
 * _12c_slave.c
 *
 * Created: 20/10/2023 04:20:32 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
   unsigned char x;
   i2c_set_address(0b11100000);
   lcd_init();
    while(1)
    {
       x=i2c_slave_read();
	   lcd_send_char(x);
    }
}