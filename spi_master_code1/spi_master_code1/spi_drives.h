/*
 * spi_drives.h
 *
 * Created: 05/08/2023 11:42:35 ص
 *  Author: handsa
 */ 


#ifndef SPI_DRIVES_H_
#define SPI_DRIVES_H_
#define ss 4
void spi_master_init(void);
void spi_slave_init(void);
unsigned char spi_master_trans_recieve(unsigned char data);
unsigned char spi_slave_trans_recieve(unsigned char data);
void spi_master_transmit_string(unsigned char*ptr);
#endif /* SPI_DRIVES_H_ */