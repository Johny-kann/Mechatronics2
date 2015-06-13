/*
 * Proj2.cpp
 *
 * Created: 6/9/2015 8:23:22 PM
 *  Author: Janakiraman
 */ 

# define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
//#include "servo.h"
#include "LcdCom.h"
#include "touch_screen.h"
//#include "items.h"
#include "opertions.h"
//#include "stepper_motor.h"
#include "pages.h"

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
	LcdDisplay lcd;
	
	touchscreen.init();
	lcd.init_lcd();
	USART_Init(MYUBRR);
	timer0_interrupt_init();
	lcd.clearDisplay();
	Pages page;
	page.introPage();
	 while (1)
	 {
		 _delay_ms(200);
	/*	 if(touchscreen.getPosX()<950 && touchscreen.getPosX()>50)
			lcd.clearDisplay();
		 lcd.gotoXY(1,5);
		 
		 lcd.displayInt(touchscreen.getPosX());
		 lcd.gotoXY(2,10);
		 lcd.displayInt(touchscreen.getPosY());
*/	page.chooseAction(touchscreen.getPosX(),touchscreen.getPosY());

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
