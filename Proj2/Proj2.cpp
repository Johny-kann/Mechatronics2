/*
 * Proj2.cpp
 *
 * Created: 6/9/2015 8:23:22 PM
 *  Author: User
 */ 

# define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "LcdCom.h"
#include "touch_screen.h"

TouchScreen touchScreen;

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

int main(void)
{
	
	USART_Init(MYUBRR);
//	USART_Sendbyte(0xFE);
//	USART_Sendbyte(0x01);
//	LcdDisplay lcd;
//	lcd.init_lcd();
//	lcd.clearDisplay();
//	int i = 1;

//	DDRC &= ~(0<<DDC1);
	
//	uint16_t adc_result ;
	sei();
	
	touchScreen.init();
	timer1_interrupt_init(50000);
	
	
//	adc_init();
	
	
		
    while(1)
    {
	//	adc_result = adc_read(1);
	USART_Send_string(" X: ");
	USART_Send_int(touchScreen.getPosX());
	USART_Send_string(" Y: ");
	USART_Send_int(touchScreen.getPosY());
	_delay_ms(1000);
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	touchScreen.setPosX(readX());
	touchScreen.setPosY(readY());
	
}