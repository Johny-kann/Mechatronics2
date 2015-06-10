/*
 * uart.h
 *
 * Created: 6/9/2015 8:24:47 PM
 *  Author: User
 */ 


#ifndef UART_H_
#define UART_H_


#define FOSC 16000000 // Clock Speed
#define BAUD 9600	  // Baud Rate
#define MYUBRR (((((FOSC * 10) / (16L * BAUD)) + 5) / 10) - 1)

void USART_Init( unsigned int ubrr);

void USART_Sendbyte( unsigned char data );
void USART_Send_string(const char *str);
void USART_Send_int(unsigned int d);

unsigned char USART_Receive( void );


#endif /* UART_H_ */