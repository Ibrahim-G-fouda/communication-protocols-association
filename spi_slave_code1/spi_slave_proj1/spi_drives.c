/*
 * spi_drives.c
 *
 * Created: 05/08/2023 11:42:11 ص
 *  Author: handsa
 */
#include "prog init.h"
void spi_master_init(void)
{
	dio_set_pin('b',4,1);//enable ss
		dio_set_pin('b',5,1);//enable mosi
			dio_set_pin('b',7,1);//enable SCk
			set_bit(SPCR,MSTR);//uc is master
			set_bit(SPCR,SPR0);//prescaller 1/16
			set_bit(SPCR,SPE);//enable spi
			set_bit(PORTA,ss);
			
	
}
void spi_slave_init(void)
{
			set_bit(SPCR,SPE);//enable spi
			dio_set_pin('b',6,1);// enable MISO
}
unsigned char spi_master_trans_recieve(unsigned char data)
{
	dio_write_pin('b',4,0);//send 0 to ss of slave to enable
	SPDR=data;//to slave
	while(read_bit(SPSR,SPIF)==0);//wait until exchange finish
	return SPDR;//data which i get from slave 
}
unsigned char spi_slave_trans_recieve(unsigned char data)
{
		SPDR=data;//to master
			dm(300);
			while(read_bit(SPSR,SPIF)==0);//wait until exchange finish
return SPDR;//data which i get from master
}

void spi_master_transmit_string(unsigned char*ptr)
{
	while ((*ptr)!=0)
	{
	spi_master_trans_recieve(*ptr);
	dm(300);//wait so that lcd can show the dsta
	ptr++;
	}
}

