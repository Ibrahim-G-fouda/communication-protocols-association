/*
 * I2c_master.c
 *
 * Created: 20/10/2023 02:01:10 م
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{

  unsigned char counter =0;
  i2c_clock_init(50000);
	while(counter<10)
    {
         dm(500);
		 i2c_start();

		 i2c_adress(0b11100000);
		 i2c_data(counter+48);
		 i2c_stop();
		 counter++;
    }
}