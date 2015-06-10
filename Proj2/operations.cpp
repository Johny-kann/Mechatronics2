/*
 * operations.cpp
 *
 * Created: 6/10/2015 7:18:05 PM
 *  Author: Janakiraman
 */ 

#include "opertions.h"
# define F_CPU 16000000L
#include <util/delay.h>
#include <avr/interrupt.h>





void adc_init()
{
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADEN);
}

void timer1_interrupt_init(unsigned int number)
{
	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12;
	TIMSK1 = 1 << OCIE1A;
	OCR1A = number;
	
}

//ISR(ADC_vect)
//{
//
//	USART_Send_string("Int");
//	USART_Send_int(ADC);
//	USART_Send_string("pt");
//}

uint16_t adc_read(uint8_t ch)
{
	ch &= 0b00000111;
	ADMUX = (ADMUX & 0xF8)|ch;

	ADCSRA |= (1<<ADSC);
	
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}

uint16_t readX()
{
	
	DDRC &= ~(1<<DDC0 | 1<<DDC2);
	DDRC |= (1<<DDC1 | 1<<DDC3);
	
	PORTC &= ~(1<<PORTC1);
	PORTC |=  (1<<PORTC3);
	
	_delay_ms(5);
	
	return adc_read(0);
	
}

uint16_t readY()
{
	DDRC &= ~(1<<DDC1 | 1<<DDC3);
	DDRC |= (1<<DDC0 | 1<<DDC2);
	
	PORTC &= ~(1<<PORTC0);
	PORTC |=  (1<<PORTC2);
	
	_delay_ms(5);
	
	return adc_read(1);
}
