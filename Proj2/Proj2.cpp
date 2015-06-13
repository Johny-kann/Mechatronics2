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
//#include "servo.h"
//#include "LcdCom.h"
#include "touch_screen.h"
//#include "items.h"
#include "opertions.h"
//#include "stepper_motor.h"

TouchScreen touchscreen;
//int count = 0 ;

/*void timer1_interrupt_init(unsigned int number)
{
	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12;
	TIMSK1 = 1 << OCIE1A;
	OCR1A = number;
	
}
*/

/*void timer0_interrupt_init()
{
	
	TCCR0B |= 1<< CS01 | 1<<CS00 | 1<<CS02;
	//| 1<<WGM02;
	TIMSK0 = 1 << OCIE0A;
	//	OCR0A = number;
	
}*/

int main(void)
{
	sei();
	//count = 0;
	touchscreen.init();
	USART_Init(MYUBRR);
	timer0_interrupt_init();

	
	
	 while (1)
	 {
		 _delay_ms(500);

	/*	USART_Send_string(" X: ");
		USART_Send_int(touchscreen.getPosX());
		USART_Send_string(" Y: ");
		USART_Send_int(touchscreen.getPosY());
		*/

	 }
}



/*ISR(TIMER1_COMPA_vect)
{
//	touchscreen.setPosX(readX());
//	touchscreen.setPosY(readY());


}*/

ISR(TIMER0_COMPA_vect)
{

static uint16_t count = 0;
	if(count == 500)
	{
	touchscreen.setPosX(readX());
	touchscreen.setPosY(readY());	
	count=0;

	}
	count++;
	
	
}
