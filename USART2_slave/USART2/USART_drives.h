/*
 * USART_drives.h
 *
 * Created: 01/08/2023 07:06:23 م
 *  Author: handsa
 */ 


#ifndef USART_DRIVES_H_
#define USART_DRIVES_H_
void UART_init(unsigned long baud);
void UART_send_char(unsigned char data);
void UART_send_string(char*ptr);
char UART_recieve_char(void);




#endif /* USART_DRIVES_H_ */