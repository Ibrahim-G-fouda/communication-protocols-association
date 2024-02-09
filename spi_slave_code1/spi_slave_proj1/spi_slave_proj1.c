/*
 * spi_slave_proj1.c
 *
 * Created: 05/08/2023 12:36:24 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
 lcd_init();
 spi_slave_init();

 unsigned char x=48;
  unsigned char z=0;
 
  while(z<=9)
  {
  
   x=spi_slave_trans_recieve(x);
   lcd_send_char(x);
   z++;


  }   
dm(1000);
lcd_clrscrean();

lcd_send_string("ibrahim the king");
}