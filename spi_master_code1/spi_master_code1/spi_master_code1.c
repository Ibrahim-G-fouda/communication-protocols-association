/*
 * spi_master_code1.c
 *
 * Created: 05/08/2023 11:39:07 ص
 *  Author: handsa
 */ 


#include <avr/io.h>
#include "prog init.h"
int main(void)
{
   spi_master_init();
   unsigned char counter=0;
 dm(300);
   while (counter<=9)
   {
   spi_master_trans_recieve(counter+48);
dm(300);
   counter++;
   }


}